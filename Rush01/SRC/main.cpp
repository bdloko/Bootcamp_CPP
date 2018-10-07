/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:50:42 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 18:39:09 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_gkrellm.hpp"

int 	main() {
	pid_t pid = fork();
	if (pid == 0)
	{
		std::string result;
		const char *cmd = ("top | head -10");
		std::array<char, 128> buffer;
		while(1)
		{
			std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
			if (!pipe) throw std::runtime_error("popen() failed!");
			while (!feof(pipe.get())) {
				if (fgets(buffer.data(), 128, pipe.get()) != NULL)
					result += buffer.data();
			}
		}
	}
	if (pid > 0)
	{
        //Instanciate and initialize Module classes
		CurrentModule cm = CurrentModule();
		dtModule dt = dtModule();
		HostnameModule hm = HostnameModule();
		osModule osm = osModule();
		NetworkModule nm = NetworkModule();
		HsModule hs = HsModule();
		set_all(dt, cm, hm, osm, nm, hs);


		int totalX, totalY, choice;
		int highlight = 0;
		static std::string mM [] = {"DateTime", "Current Status", "Host Info", "OS Info", "Network", "Hardware/Software", "Exit"};
		int menuLen = 10;
		std::vector<std::string> mainMenu(mM, mM+menuLen);


		//Initialize nCurses stuff
		initscr();
		noecho();
		cbreak();
		curs_set(0);
		getmaxyx(stdscr, totalY, totalX);
		CurseWindow left = CurseWindow(totalY, totalX/2);
		CurseWindow right = CurseWindow(totalY, totalX/2, 0, totalX/2);
		keypad(left.getWindow(), true);

		while(1) {
			//Get screen dimensions and resize if required
			displaySizeChange(stdscr, totalY, totalX, left, right);
			//Add menu & refresh
			for(int i = 0; i < menuLen; i++) {
				if (i == highlight)
					wattron(left.getWindow(), A_REVERSE);
				mvwprintw(left.getWindow(), left.getMidY(menuLen)+i, left.getMidX(mainMenu[i].length()), mainMenu[i].c_str());
				wattroff(left.getWindow(), A_REVERSE);
			}
			left.refreshWin();
			right.refreshWin();
			//Wait for input and preform command
			choice = wgetch(left.getWindow());
			switch(choice) {
				case KEY_UP:
				highlight--;
				if (highlight == -1)
					highlight = menuLen-1;
				break;
				case KEY_DOWN:
				highlight++;
				if (highlight == menuLen)
					highlight = 0;
				break;
				default:
				break;
			}
			if(choice == 10 && highlight == 6)
				break;
			else if (choice == 10 && highlight == 0)
				displayDT(stdscr, left, right, dt, totalY, totalX);
			else if (choice == 10 && highlight == 1)
				displayCM(stdscr, left, right, cm, totalY, totalX);
			else if (choice == 10 && highlight == 2)
				displayHM(stdscr, left, right, hm, totalY, totalX);
			else if (choice == 10 && highlight == 3)
				displayOSM(stdscr, left, right, osm, totalY, totalX);
			else if (choice == 10 && highlight == 4)
				displayNM(stdscr, left, right, nm, totalY, totalX);
			else if (choice == 10 && highlight == 5)
				displayHS(stdscr, left, right, hs, totalY, totalX);
		}
		kill(pid, SIGTERM);
		endwin();
	}
	return 0;
}

void		displaySizeChange(WINDOW * stdscr, int & totalY, int & totalX, CurseWindow & left, CurseWindow & right) {
	int newY, newX;
	getmaxyx(stdscr, newY, newX);
	if (newY != totalY || newX != totalX) {
		totalX = newX;
		totalY = newY;
		left.resizeWin(totalY, totalX/2);
		right.resizeWin(totalY, totalX/2);
		right.moveWin(0, totalX/2);
		wclear(stdscr);
	}
	left.refreshClearWin();
	right.refreshClearWin();
}	

void		displayCM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, CurrentModule & cm, int & totalY, int & totalX)
{
	int choice;
	static std::string iM [] = {"Now Viewing: Current Status.", "ESC to go back."};
	int infoLen = 10;
	std::vector<std::string> infoMenu(iM, iM+infoLen);
	keypad(left.getWindow(), true);
	while(1)
	{
		displaySizeChange(stdscr, totalY, totalX, left, right);
		for(int i = 0; i < infoLen; i++)
		{
			mvwprintw(right.getWindow(), right.getMidY(infoLen)+i, right.getMidX(infoMenu[i].length()), infoMenu[i].c_str());
			if (i == 1)
				wprintw(right.getWindow(), " system overheating", cm.getCurrentModuleLvl());
		}
		mvwprintw(left.getWindow(), 1, 1, cm.get_cpu_p().c_str());
			mvwprintw(left.getWindow(), 2, 1, cm.get_ram_p().c_str());
			mvwprintw(left.getWindow(), 3, 1, cm.get_clockspeed().c_str());
			mvwprintw(left.getWindow(), 4, 1, cm.get_model().c_str());
			mvwprintw(left.getWindow(), 5, 1, cm.get_num_cores().c_str());
		left.refreshWin();
		right.refreshWin();
		choice = wgetch(left.getWindow());
		if(choice == 27)
			break;
	}
}

void		displayHM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, HostnameModule & hm, int & totalY, int & totalX)
{
	int choice;
	static std::string iM [] = {"Now Viewing: Host Info.", "Info Level:", "ESC to go back."};
	int infoLen = 10;
	std::vector<std::string> infoMenu(iM, iM+infoLen);
	keypad(left.getWindow(), true);
	while(1)
	{
		displaySizeChange(stdscr, totalY, totalX, left, right);
		for(int i = 0; i < infoLen; i++)
		{
			mvwprintw(right.getWindow(), right.getMidY(infoLen)+i, right.getMidX(infoMenu[i].length()), infoMenu[i].c_str());
			if (i == 1)
				wprintw(right.getWindow(), " system overheating", hm.getHostnameModuleLvl());
		}
		mvwprintw(left.getWindow(), 1, 1, hm.get_username().c_str());
			mvwprintw(left.getWindow(), 2, 1, hm.get_system_id().c_str());
			mvwprintw(left.getWindow(), 3, 1, hm.get_internal_ip().c_str());
			mvwprintw(left.getWindow(), 4, 1, hm.get_external_ip().c_str());
		left.refreshWin();
		right.refreshWin();
		choice = wgetch(left.getWindow());
		if(choice == 27)
			break;
	}
}

void		displayOSM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, osModule & osm, int & totalY, int & totalX) {
	int choice;
	static std::string iM [] = {"Now Viewing: OS Info.", "ESC to go back."};
	int infoLen = 10;
	std::vector<std::string> infoMenu(iM, iM+infoLen);
	keypad(left.getWindow(), true);
	while(1)
	{
		displaySizeChange(stdscr, totalY, totalX, left, right);
		for(int i = 0; i < infoLen; i++)
		{
			mvwprintw(right.getWindow(), right.getMidY(infoLen)+i, right.getMidX(infoMenu[i].length()), infoMenu[i].c_str());
			if (i == 1)
				wprintw(right.getWindow(), " system cooling", osm.getosModuleLvl());
		}
		mvwprintw(left.getWindow(), 1, 1, osm.get_system_name().c_str());
			mvwprintw(left.getWindow(), 2, 1, osm.get_system_version().c_str());
			mvwprintw(left.getWindow(), 3, 1, osm.get_system_release().c_str());
			mvwprintw(left.getWindow(), 4, 1, osm.get_node().c_str());
			mvwprintw(left.getWindow(), 5, 1, osm.get_machine().c_str());
		left.refreshWin();
		right.refreshWin();
		choice = wgetch(left.getWindow());
		if(choice == 27)
			break;
	}
}

void		displayDT(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, dtModule & dt, int & totalY, int & totalX) {
	int choice;
	static std::string iM [] = {"Now Viewing: Date/Time Info.", "ESC to go back."};
	int infoLen = 10;
	std::vector<std::string> infoMenu(iM, iM+infoLen);
	keypad(left.getWindow(), true);
	while(1)
	{
		displaySizeChange(stdscr, totalY, totalX, left, right);
		for(int i = 0; i < infoLen; i++)
		{
			mvwprintw(right.getWindow(), right.getMidY(infoLen)+i, right.getMidX(infoMenu[i].length()), infoMenu[i].c_str());
			if (i == 1)
				wprintw(right.getWindow(), " system cooling", dt.getdtModuleLvl());
		}
		mvwprintw(left.getWindow(), 1, 1, dt.get_time().c_str());
		mvwprintw(left.getWindow(), 2, 1, dt.get_date().c_str());
		mvwprintw(left.getWindow(), 3, 1, dt.get_day().c_str());
		mvwprintw(left.getWindow(), 4, 1, dt.get_week().c_str());
		mvwprintw(left.getWindow(), 5, 1, dt.get_month().c_str());
		mvwprintw(left.getWindow(), 6, 1, dt.get_year().c_str());
		left.refreshWin();
		right.refreshWin();
		choice = wgetch(left.getWindow());
		if(choice == 27) 
			break;
	}
}


void		displayNM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, NetworkModule & nm, int & totalY, int & totalX) {
	int choice;
	static std::string iM [] = {"Now Viewing: Network Info.", "ESC to go back."};
	int infoLen = 10;
	std::vector<std::string> infoMenu(iM, iM+infoLen);
	keypad(left.getWindow(), true);
	while(1) {
		displaySizeChange(stdscr, totalY, totalX, left, right);
		for(int i = 0; i < infoLen; i++) {
			mvwprintw(right.getWindow(), right.getMidY(infoLen)+i, right.getMidX(infoMenu[i].length()), infoMenu[i].c_str());
			if (i == 1)
				wprintw(right.getWindow(), "system cooling", nm.getNetworkModuleLvl());
		}
		mvwprintw(left.getWindow(), 1, 1, nm.get_packages_in().c_str());
			mvwprintw(left.getWindow(), 2, 1, nm.get_packages_out().c_str());
			mvwprintw(left.getWindow(), 3, 1, nm.get_router_ip().c_str());
			mvwprintw(left.getWindow(), 4, 1, nm.get_domain_name_server().c_str());
			mvwprintw(left.getWindow(), 5, 1, nm.get_domain_search().c_str());

		left.refreshWin();
		right.refreshWin();
		choice = wgetch(left.getWindow());
		if(choice == 27)
			break;
	}
}

void		displayHS(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, HsModule & hs, int & totalY, int & totalX) {
	int choice;
	static std::string iM [] = {"Now Viewing: H/S Info.", "ESC to go back."};
	int infoLen = 30;
	std::vector<std::string> infoMenu(iM, iM+infoLen);
	keypad(left.getWindow(), true);
	while(1)
	{
		displaySizeChange(stdscr, totalY, totalX, left, right);
		for(int i = 0; i < infoLen; i++)
		{
			mvwprintw(right.getWindow(), right.getMidY(infoLen)+i, right.getMidX(infoMenu[i].length()), infoMenu[i].c_str());
			if (i == 1)
				wprintw(right.getWindow(), " system cooling", hs.getHsModuleLvl());
		}
		mvwprintw(left.getWindow(), 1, 1, hs.get_soft().c_str());
			mvwprintw(left.getWindow(), 20, 1, hs.get_hard().c_str());
		left.refreshWin();
		right.refreshWin();
		choice = wgetch(left.getWindow());
		if(choice == 27)
			break;
	}
}

std::string     set_(const char *cmd)
{
	std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != NULL)
			result += buffer.data();
	}
	return result;
}


void            set_all(dtModule & dt, CurrentModule & cm, HostnameModule & hm, osModule & osm, NetworkModule & nm, HsModule & hs)
{
	dt.set_time(set_("date '+%X'"));
	dt.set_date(set_("date '+%D'"));
	dt.set_day(set_("date '+%A'"));
	dt.set_week(set_("date '+%W'"));
	dt.set_month(set_("date '+%m'"));
	dt.set_year(set_("date '+%Y'"));

	cm.set_cpu_p("CPU Usage: " + set_("echo `ps -A -o %cpu | awk '{s+=$1} END {print s \"%\"}'`%"));
	cm.set_ram_p("RAM Usage: " + set_("echo `ps -A -o %mem | awk '{s+=$1} END {print s \"%\"}'`%"));
	cm.set_clockspeed("CPU Clock: " + set_("sysctl -n machdep.cpu.brand_string | cut -d\" \" -f 6"));
	cm.set_model("CPU Model: " + set_("sysctl -n machdep.cpu.brand_string | cut -d\" \" -f 1-3"));
	cm.set_num_cores("CPU Cores: " + set_("sysctl -n hw.ncpu"));

	hm.set_username("Username: " + set_("whoami"));
	hm.set_system_id("Hostname: " + set_("hostname -s"));
	hm.set_external_ip("Public IP: " + set_("dig TXT +short o-o.myaddr.l.google.com @ns1.google.com | awk -F'\"' '{ print $2}'"));
	hm.set_internal_ip("Local IP: " + set_("ifconfig | grep -Eo 'inet (addr:)?([0-9]*\\.){3}[0-9]*' | grep -Eo '([0-9]*\\.){3}[0-9]*' | grep -v '127.0.0.1'"));

	nm.set_packages_in(set_("top | head -9 | tail -1 | rev | cut -d: -f-2 | rev | sed 's/,/:/g' | sed 's/out//g' | sed 's/packets/packets in/g' | cut -d \" \" -f1-4"));
	nm.set_packages_out(set_("top | head -9 | tail -1 | rev | cut -d: -f-2 | rev | sed 's/,/:/g' | sed 's/out//g' | sed 's/packets/packets in/g' | cut -d \" \" -f5-6 | sed 's/in/packets out/g'"));
	nm.set_router_ip(set_("ipconfig getpacket en0 | grep 'router'"));
	nm.set_domain_name_server(set_("ipconfig getpacket en0 | grep 'domain_name_server'"));
	nm.set_domain_search(set_("ipconfig getpacket en0 | grep 'domain_search'"));

	struct utsname name;
	if(uname(&name)) exit(0);
	osm.set_system_name(name.sysname);
	osm.set_system_version(name.version);
	osm.set_system_release(name.release);
	osm.set_node(name.nodename);
	osm.set_machine(name.machine);

	hs.set_hard(set_("system_profiler SPHardwareDataType"));
	hs.set_soft(set_("system_profiler SPSoftwareDataType"));
}
