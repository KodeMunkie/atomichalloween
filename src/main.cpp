/* Atomic Halloween - Halloween animations for M5Atom
 * Copyright (C) 2020 Silent Software (Benjamin Brown)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <M5Atom.h>
#include "anims/pumpkin.h"
#include "anims/skeleton.h"
#include "anims/spaceInvader.h"
#include "anims/ghost.h"

CRGB leds[25];
void (*anims[4])(CRGB* leds) {pumpkin, skeleton, spaceInvader, ghost};

void setup()
{
    M5.begin(false, false, true);
    FastLED.addLeds<WS2812B, 27>(leds, 25);
}

uint8_t animIndex = 0;
int iterations = 1;

/**
 * This code is all a bit of fun for my 1 and 5 year olds
 * - the icons were designed and the program written in a 
 * couple of hours before Halloween - hope you get some
 * enjoyment out of it too!
 * 
 * Feel free to submit new MRs for icons, improved playback,
 * different holidays etc. It's all a bit of pointless fun :)
 * 
 * Nb. if you're snooping for quality code this is not it - 
 * magic numbers, no tests, no code comments etc...!
 */
void loop()
{
    (*anims[animIndex])(leds);
    if (iterations % 10 == 0 ) {
       ++animIndex;
       animIndex%=4; 
    }
    ++iterations;
}