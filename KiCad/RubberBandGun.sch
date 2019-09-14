EESchema Schematic File Version 2
LIBS:RubberBandGun-rescue
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:mdoLibrary
LIBS:Arduino_Nano-cache
LIBS:RubberBandGun-cache
EELAYER 25 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 2
Title "Rubber Band Gun"
Date "2019-09-13"
Rev "---"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +12V #PWR?
U 1 1 5A3DEBB7
P 1250 3850
F 0 "#PWR?" H 1250 3700 50  0001 C CNN
F 1 "+12V" H 1250 3990 50  0000 C CNN
F 2 "" H 1250 3850 50  0001 C CNN
F 3 "" H 1250 3850 50  0001 C CNN
	1    1250 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A3DEBCE
P 1250 4950
F 0 "#PWR?" H 1250 4700 50  0001 C CNN
F 1 "GND" H 1250 4800 50  0000 C CNN
F 2 "" H 1250 4950 50  0001 C CNN
F 3 "" H 1250 4950 50  0001 C CNN
	1    1250 4950
	1    0    0    -1  
$EndComp
$Comp
L LEDring Z?
U 1 1 5A458774
P 9900 1100
F 0 "Z?" H 9900 1100 60  0000 C CNN
F 1 "LEDring" H 9900 1250 60  0000 C CNN
F 2 "" H 9900 1250 60  0001 C CNN
F 3 "" H 9900 1250 60  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A459198
P 5200 2200
F 0 "R?" V 5280 2200 50  0000 C CNN
F 1 "220 ohm" V 5100 2200 50  0000 C CNN
F 2 "" V 5130 2200 50  0001 C CNN
F 3 "" H 5200 2200 50  0001 C CNN
	1    5200 2200
	0    1    1    0   
$EndComp
$Comp
L UBEC J?
U 1 1 5A459C5D
P 2050 4450
F 0 "J?" H 2050 4450 60  0000 C CNN
F 1 "UBEC" H 2050 4550 60  0000 C CNN
F 2 "" H 2050 4450 60  0001 C CNN
F 3 "" H 2050 4450 60  0001 C CNN
	1    2050 4450
	1    0    0    -1  
$EndComp
$Comp
L UBEC J?
U 1 1 5A459D02
P 2050 6250
F 0 "J?" H 2050 6250 60  0000 C CNN
F 1 "UBEC" H 2050 6350 60  0000 C CNN
F 2 "" H 2050 6250 60  0001 C CNN
F 3 "" H 2050 6250 60  0001 C CNN
	1    2050 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A45A4D2
P 1250 6950
F 0 "#PWR?" H 1250 6700 50  0001 C CNN
F 1 "GND" H 1250 6800 50  0000 C CNN
F 2 "" H 1250 6950 50  0001 C CNN
F 3 "" H 1250 6950 50  0001 C CNN
	1    1250 6950
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR?
U 1 1 5A45A52D
P 1250 5550
F 0 "#PWR?" H 1250 5400 50  0001 C CNN
F 1 "+12V" H 1250 5690 50  0000 C CNN
F 2 "" H 1250 5550 50  0001 C CNN
F 3 "" H 1250 5550 50  0001 C CNN
	1    1250 5550
	1    0    0    -1  
$EndComp
$Comp
L Arduino A?
U 1 1 5A480803
P 5950 2400
F 0 "A?" H 5950 2400 60  0000 C CNN
F 1 "Arduino" H 5950 2500 60  0000 C CNN
F 2 "" H 5950 2400 60  0000 C CNN
F 3 "" H 5950 2400 60  0000 C CNN
	1    5950 2400
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW?
U 1 1 5A4908F2
P 3600 4300
F 0 "SW?" H 3750 4410 50  0000 C CNN
F 1 "SW_PUSH" H 3600 4220 50  0000 C CNN
F 2 "" H 3600 4300 60  0000 C CNN
F 3 "" H 3600 4300 60  0000 C CNN
	1    3600 4300
	0    -1   -1   0   
$EndComp
$Comp
L SW_Push SW?
U 1 1 5A490A22
P 4000 4300
F 0 "SW?" H 4150 4410 50  0000 C CNN
F 1 "SW_PUSH" H 4000 4220 50  0000 C CNN
F 2 "" H 4000 4300 60  0000 C CNN
F 3 "" H 4000 4300 60  0000 C CNN
	1    4000 4300
	0    -1   -1   0   
$EndComp
$Comp
L SW_Push SW?
U 1 1 5A490A65
P 3800 5000
F 0 "SW?" H 3950 5110 50  0000 C CNN
F 1 "SW_PUSH" H 3800 4920 50  0000 C CNN
F 2 "" H 3800 5000 60  0000 C CNN
F 3 "" H 3800 5000 60  0000 C CNN
	1    3800 5000
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5A49671E
P 3600 1250
F 0 "R?" V 3680 1250 50  0000 C CNN
F 1 "10K" V 3600 1250 50  0000 C CNN
F 2 "" V 3530 1250 30  0000 C CNN
F 3 "" H 3600 1250 30  0000 C CNN
	1    3600 1250
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A496756
P 3800 1250
F 0 "R?" V 3880 1250 50  0000 C CNN
F 1 "10K" V 3800 1250 50  0000 C CNN
F 2 "" V 3730 1250 30  0000 C CNN
F 3 "" H 3800 1250 30  0000 C CNN
	1    3800 1250
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A496794
P 4000 1250
F 0 "R?" V 4080 1250 50  0000 C CNN
F 1 "10K" V 4000 1250 50  0000 C CNN
F 2 "" V 3930 1250 30  0000 C CNN
F 3 "" H 4000 1250 30  0000 C CNN
	1    4000 1250
	1    0    0    -1  
$EndComp
Text Notes 5600 1500 0    60   ~ 0
Arduino 1 of 2
$Comp
L R R?
U 1 1 5A767559
P 4200 1250
F 0 "R?" V 4280 1250 50  0000 C CNN
F 1 "10K" V 4200 1250 50  0000 C CNN
F 2 "" V 4130 1250 30  0000 C CNN
F 3 "" H 4200 1250 30  0000 C CNN
	1    4200 1250
	1    0    0    -1  
$EndComp
Connection ~ 3050 6400
Wire Wire Line
	1250 6000 1250 5550
Wire Wire Line
	1550 6000 1250 6000
Wire Wire Line
	1250 6400 1250 6950
Wire Wire Line
	1550 6400 1250 6400
Wire Wire Line
	9850 6400 2750 6400
Wire Wire Line
	9850 1800 9850 6400
Wire Wire Line
	3050 4600 3050 6400
Wire Wire Line
	2750 4600 3050 4600
Wire Wire Line
	1250 4200 1550 4200
Wire Wire Line
	1250 3850 1250 4200
Wire Wire Line
	1250 4600 1550 4600
Wire Wire Line
	1250 4950 1250 4600
Wire Wire Line
	3200 4200 2750 4200
Wire Wire Line
	3200 950  3200 4200
Connection ~ 3400 6400
Wire Wire Line
	3400 6400 3400 2000
Wire Wire Line
	3400 2000 5350 2000
Wire Wire Line
	5050 2200 4900 2200
Wire Wire Line
	4900 2200 4900 700 
Wire Wire Line
	4900 700  9300 700 
Wire Wire Line
	5350 2300 3600 2300
Wire Wire Line
	3600 1400 3600 4000
Wire Wire Line
	5350 2400 3800 2400
Wire Wire Line
	3800 1400 3800 4700
Wire Wire Line
	5350 2500 4000 2500
Wire Wire Line
	4000 1400 4000 4000
Wire Wire Line
	3600 4600 3600 6400
Connection ~ 3600 6400
Wire Wire Line
	3800 5300 3800 6400
Connection ~ 3800 6400
Wire Wire Line
	4000 4600 4000 6400
Connection ~ 4000 6400
Wire Wire Line
	3600 1100 3600 950 
Connection ~ 3600 950 
Wire Wire Line
	3800 1100 3800 950 
Connection ~ 3800 950 
Wire Wire Line
	4000 1100 4000 950 
Connection ~ 4000 950 
Connection ~ 3600 2300
Connection ~ 3800 2400
Connection ~ 4000 2500
Wire Wire Line
	2750 6000 9950 6000
Wire Wire Line
	9950 6000 9950 1800
Wire Wire Line
	9300 700  9300 1950
Wire Wire Line
	9300 1950 10050 1950
Wire Wire Line
	10050 1950 10050 1800
Wire Wire Line
	9750 1800 9750 1850
Wire Wire Line
	9750 1850 9850 1850
Connection ~ 9850 1850
$Sheet
S 2150 7250 500  150 
U 5B063CC5
F0 "RubberBandWiring" 197
F1 "RubberBandWiring.sch" 197
$EndSheet
$Comp
L WT588D A?
U 1 1 5D7C6302
P 6200 5050
F 0 "A?" H 6200 5050 60  0000 C CNN
F 1 "WT588D" H 6200 4950 60  0000 C TNN
F 2 "" H 6200 5050 60  0000 C CNN
F 3 "" H 6200 5050 60  0000 C CNN
	1    6200 5050
	1    0    0    -1  
$EndComp
$Comp
L Speaker LS?
U 1 1 5D7C69A9
P 5300 4550
F 0 "LS?" H 5350 4775 50  0000 R CNN
F 1 "Speaker" H 5350 4700 50  0000 R CNN
F 2 "" H 5300 4350 50  0001 C CNN
F 3 "" H 5290 4500 50  0001 C CNN
	1    5300 4550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5500 4550 5600 4550
Wire Wire Line
	5500 4650 5600 4650
Wire Wire Line
	5600 5050 5600 6400
Connection ~ 5600 6400
Wire Wire Line
	5350 2700 4450 2700
Wire Wire Line
	4450 2700 4450 5700
Wire Wire Line
	4450 5700 7500 5700
Wire Wire Line
	7500 5700 7500 4750
Wire Wire Line
	7500 4750 6800 4750
Wire Wire Line
	5350 2800 4600 2800
Wire Wire Line
	4600 2800 4600 5550
Wire Wire Line
	4600 5550 7300 5550
Wire Wire Line
	7300 5550 7300 4850
Wire Wire Line
	7300 4850 6800 4850
Wire Wire Line
	5350 2900 4750 2900
Wire Wire Line
	4750 2900 4750 5400
Wire Wire Line
	4750 5400 7100 5400
Wire Wire Line
	7100 5400 7100 4950
Wire Wire Line
	7100 4950 6800 4950
Wire Wire Line
	6800 4450 7700 4450
Wire Wire Line
	7700 4450 7700 5850
Wire Wire Line
	7700 5850 4300 5850
Wire Wire Line
	4300 5850 4300 2600
Wire Wire Line
	4300 2600 5350 2600
$Comp
L ARD_of_4 A?
U 1 1 5A7681AD
P 7850 3600
F 0 "A?" H 7850 3600 60  0000 C CNN
F 1 "ARD_of_2" H 7850 3700 60  0000 C CNN
F 2 "" H 7850 3600 60  0001 C CNN
F 3 "" H 7850 3600 60  0001 C CNN
	1    7850 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 3000 7000 3000
Wire Wire Line
	7000 3000 7000 4550
Wire Wire Line
	7000 4550 6800 4550
Wire Wire Line
	7400 3800 3600 3800
Connection ~ 3600 3800
Wire Wire Line
	6550 2000 7400 2000
Wire Wire Line
	7400 950  7400 3400
Wire Wire Line
	3200 950  7400 950 
Connection ~ 7400 2000
Connection ~ 3800 3800
Connection ~ 4000 3800
$EndSCHEMATC
