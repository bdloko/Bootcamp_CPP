/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:52:55 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 15:51:07 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTFKRELLM_HPP
#define FTFKRELLM_HPP

#include <ncurses.h>
#include "CurrentModule.hpp"
#include "NetworkModule.hpp"
#include "CurseWindow.hpp"
#include "HostnameModule.hpp"
#include "osModule.hpp"
#include "HardwareSoftware.hpp"
#include "timedateModule.hpp"
#include <stdlib.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sysctl.h>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <signal.h>

void						displaySizeChange(WINDOW * stdscr, int & totalY, int & totalX, CurseWindow & left, CurseWindow & right);
void						displayDT(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, dtModule & dt, int & totalY, int & totalX);
void						displayCM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, CurrentModule & cm, int & totalY, int & totalX);
void						displayHM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, HostnameModule & hm, int & totalY, int & totalX);
void						displayOSM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, osModule & osm, int & totalY, int & totalX);
void						displayDTM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, int & totalY, int & totalX);
void						displayNM(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, NetworkModule & nm, int & totalY, int & totalX);
void						displayHS(WINDOW * stdscr, CurseWindow & left, CurseWindow & right, HsModule & hs, int & totalY, int & totalX);
void        				set_all(dtModule & dt, CurrentModule & cm, HostnameModule & hm, osModule & osm, NetworkModule & nm, HsModule & hs);
#endif
