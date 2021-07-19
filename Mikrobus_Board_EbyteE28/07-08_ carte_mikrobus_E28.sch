EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 6200 3500 2    50   Input ~ 0
TXEN
Text GLabel 6200 2550 2    50   Input ~ 0
TXEN
Text GLabel 4700 2550 0    50   Input ~ 0
RXEN
Text GLabel 6200 3600 2    50   Input ~ 0
RXEN
Text GLabel 6200 1850 2    50   Input ~ 0
GND
Text GLabel 6200 2450 2    50   Input ~ 0
GND
Text GLabel 4700 1950 0    50   Input ~ 0
GND
Text GLabel 4700 2450 0    50   Input ~ 0
GND
Text GLabel 4600 4000 0    50   Input ~ 0
GND
Text GLabel 6200 4000 2    50   Input ~ 0
GND
Text GLabel 4600 3900 0    50   Input ~ 0
VCC
Text GLabel 4700 1850 0    50   Input ~ 0
VCC
Text GLabel 4700 2150 0    50   Input ~ 0
MOSI
Text GLabel 4600 3800 0    50   Input ~ 0
MOSI
Text GLabel 4700 2050 0    50   Input ~ 0
MISO
Text GLabel 4600 3700 0    50   Input ~ 0
MISO
Text GLabel 4700 2250 0    50   Input ~ 0
SCK
Text GLabel 4600 3600 0    50   Input ~ 0
SCK
Text GLabel 4600 3500 0    50   Input ~ 0
NSS
Text GLabel 4700 2350 0    50   Input ~ 0
NSS
Text GLabel 4600 3400 0    50   Input ~ 0
RESET
Text GLabel 6200 2350 2    50   Input ~ 0
RESET
Text GLabel 4600 3300 0    50   Input ~ 0
BUSY
Text GLabel 6200 2250 2    50   Input ~ 0
BUSY
Text GLabel 6200 2150 2    50   Input ~ 0
DIO1
Text GLabel 6200 2050 2    50   Input ~ 0
DIO2
Text GLabel 6200 1950 2    50   Input ~ 0
DIO3
Text GLabel 6200 3400 2    50   Input ~ 0
DIO1
Text GLabel 6200 3300 2    50   Input ~ 0
DIO2
Wire Wire Line
	4700 1850 4900 1850
Wire Wire Line
	4900 1950 4700 1950
Wire Wire Line
	4700 2050 4900 2050
Wire Wire Line
	4900 2150 4700 2150
Wire Wire Line
	4700 2250 4900 2250
Wire Wire Line
	4900 2350 4700 2350
Wire Wire Line
	4700 2450 4900 2450
Wire Wire Line
	4900 2550 4700 2550
Wire Wire Line
	6000 1850 6200 1850
Wire Wire Line
	6200 1950 6000 1950
Wire Wire Line
	6000 2050 6200 2050
Wire Wire Line
	6200 2150 6000 2150
Wire Wire Line
	6000 2250 6200 2250
Wire Wire Line
	6200 2350 6000 2350
Wire Wire Line
	6000 2450 6200 2450
Wire Wire Line
	6200 2550 6000 2550
Wire Wire Line
	6200 3300 6000 3300
Wire Wire Line
	6000 3400 6200 3400
Wire Wire Line
	6200 3500 6000 3500
Wire Wire Line
	6000 3600 6200 3600
Wire Wire Line
	6200 4000 6000 4000
Wire Wire Line
	4800 3300 4600 3300
Wire Wire Line
	4600 3400 4800 3400
Wire Wire Line
	4800 3500 4600 3500
Wire Wire Line
	4600 3600 4800 3600
Wire Wire Line
	4800 3700 4600 3700
Wire Wire Line
	4600 3800 4800 3800
Wire Wire Line
	4800 3900 4600 3900
Wire Wire Line
	4600 4000 4800 4000
Text GLabel 3500 1900 0    50   Input ~ 0
VCC
Text GLabel 3500 2500 0    50   Input ~ 0
GND
$Comp
L Device:C C1
U 1 1 60EDD5D6
P 3600 2200
F 0 "C1" H 3715 2246 50  0000 L CNN
F 1 "100nF" H 3715 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 3638 2050 50  0001 C CNN
F 3 "~" H 3600 2200 50  0001 C CNN
	1    3600 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1900 3600 1900
Wire Wire Line
	3600 1900 3600 2050
Wire Wire Line
	3500 2500 3600 2500
Wire Wire Line
	3600 2500 3600 2350
$Comp
L Lib_E28-2G4M12-20S:E28 E28_2G4M12-20S1
U 1 1 60EE2742
P 5400 1350
F 0 "E28_2G4M12-20S1" H 5450 1115 50  0000 C CNN
F 1 "E28" H 5450 1024 50  0000 C CNN
F 2 "LIB_E28-2G4M12-20S:E28-2G4M12-20S" H 5400 1050 50  0001 C CNN
F 3 "" H 5400 1050 50  0001 C CNN
	1    5400 1350
	1    0    0    -1  
$EndComp
$Comp
L MIKROE-924:MIKROE-924 IC1
U 1 1 60F59DC9
P 4800 3300
F 0 "IC1" H 5400 3565 50  0000 C CNN
F 1 "MIKROE-924" H 5400 3474 50  0000 C CNN
F 2 "MIKROE-924:MIKROE924" H 5850 3400 50  0001 L CNN
F 3 "https://www.mikroe.com/microsd-click" H 5850 3300 50  0001 L CNN
F 4 "microSD click mikroBUS" H 5850 3200 50  0001 L CNN "Description"
F 5 "5" H 5850 3100 50  0001 L CNN "Height"
F 6 "MIKROELEKTRONIKA" H 5850 3000 50  0001 L CNN "Manufacturer_Name"
F 7 "MIKROE-924" H 5850 2900 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "932-MIKROE-924" H 5850 2800 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.com/Search/Refine.aspx?Keyword=932-MIKROE-924" H 5850 2700 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 5850 2600 50  0001 L CNN "Arrow Part Number"
F 11 "" H 5850 2500 50  0001 L CNN "Arrow Price/Stock"
	1    4800 3300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
