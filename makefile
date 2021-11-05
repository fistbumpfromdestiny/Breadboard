breadboard: main.c check_direction.c find_connection.c place_resistor.c print.c remove_resistor.c
	gcc -Wall main.c check_direction.c find_connection.c place_resistor.c print.c remove_resistor.c -o breadboard

clean:
	rm breadboard


