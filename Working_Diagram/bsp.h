/*$file${.::bsp.h} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: blinky_console.qm
* File:  ${.::bsp.h}
*
* This code has been generated by QM 5.2.5 <www.state-machine.com/qm>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* SPDX-License-Identifier: GPL-3.0-or-later
*
* This generated code is open source software: you can redistribute it under
* the terms of the GNU General Public License as published by the Free
* Software Foundation.
*
* This code is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* NOTE:
* Alternatively, this generated code may be distributed under the terms
* of Quantum Leaps commercial licenses, which expressly supersede the GNU
* General Public License and are specifically designed for licensees
* interested in retaining the proprietary status of their code.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*/
/*$endhead${.::bsp.h} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#ifndef BSP_H
#define BSP_H

/* a very simple Board Support Package (BSP) -------------------------------*/
enum { BSP_TICKS_PER_SEC = 100 }; /* number of clock ticks in a second */
void BSP_init(void);
void BSP_ledOff(void);
void BSP_ledOn(void);

/* define the event signals used in the application ------------------------*/
enum BlinkySignals {
    TIMEOUT_SIG = Q_USER_SIG, /* offset the first signal by Q_USER_SIG */
    MAX_SIG /* keep last (the number of signals) */
};

/* active object(s) used in this application -------------------------------*/
extern QActive * const AO_Blinky; /* opaque pointer to the Blinky AO */
/*$declare${AOs::Blinky_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${AOs::Blinky_ctor} ......................................................*/
void Blinky_ctor(void);
/*$enddecl${AOs::Blinky_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

#endif /* BSP_H */
