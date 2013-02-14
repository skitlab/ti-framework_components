/* --COPYRIGHT--,BSD
 * Copyright (c) $(CPYYEAR), Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--
 */
var memory = [];

memory[0] = ["DDR2",
	{
		name: "DDR2",
		base: 0xe0000000,
		len: 0x10000000,
		space: "code/data"
	}];

memory[1] = ["IRAM",
	{
		name: "IRAM",
		base: 0x800000,
		len: 0x200000,
		space: "code/data"
	}];

memory[2] = ["CACHE_L1D",
	{
		name: "CACHE_L1D",
		base: 0xf06000,
		len: 0x2000,
		space: "Cache"
	}];

memory[3] = ["CACHE_L1P",
	{
		name: "CACHE_L1P",
		base: 0xe00000,
		len: 0x8000,
		space: "Cache"
	}];

memory[4] = ["L1DSRAM",
	{
		name: "L1DSRAM",
		base: 0xf00000,
		len: 0x6000,
		space: "data"
	}];

Build.platformTable['ti.platforms.generic:C6455'] = {
	clockRate: 1000,
	catalogName: 'ti.catalog.c6000',
	deviceName: 'TMS320C6455',
	l1DMode: '8k',
	customMemoryMap: memory
};

