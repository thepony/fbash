/*
 fbash - Fake Bash by G Colburn (Used for Honeypots!)
 
 Fake Login / bash prompt for honeypot servers. logs to a text file any keystrokes used. Can be set up
 for faking a terminal to see what actions a comprimised system might incurr during a breach. You have
 to set up the corresponding directory to run this on login to function correctly with the honeypot
 login. results may vary depending on system... Use extreme caution if using this that it cannot be
 elevated or circumvented!!
 
 This is also a simple example of logging in a file, captureing stdin user input -- Feel free to
 share or use, please give credit, its all I ask. Feel free to donate to my coding habit via bitcoin
 
 1K6hdkYQthme7o1eTp9bjKhY1jQikrS7VQ
 
 it helps fund the chips and caffine!
 */


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

FILE *logger;
char input[256];

char *myname = "Ubuntu 14.04 LTS";
char *syswas = "Idle - Inactive";
char *sysnow = "Active with Admin Login";

char *pr = "bash-4.3$ ";

void main() {
    system("clear");
    usleep(250 * 1000);
    printf("Welcome to %s -- Server Status: Linked | Comm: 10ms\n", myname);
    usleep(500 * 1000);
    printf("\nSystem was: %s\n", syswas);
    usleep(500 * 1000);
    printf("\nSystem now: %s\n", sysnow);
    printf("\n \n");
    
startover:
    logger = fopen("honeypot.log", "a+");
    printf("%s", pr);
    fgets(input, 256, stdin);
    fprintf(logger, "[%d]:%s\n", (int)time(NULL), input);
    fclose(logger);
    if(strcasestr(input, "exit")) return;
    goto startover;
}