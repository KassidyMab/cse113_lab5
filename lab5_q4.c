 /**
 * @file lab5_q4.c
 *
 * @author Kassidy Maberry
 *
 * @date 3/12/2022
 *
 * Assignment: Lab 5
 *
 * @brief a program that will tell you someone's sign depending on their birth
 * date.
 *
 * @details A program that will take in a person's birth date and return 
 * their sign.
 *
 * @bugs none
 *
 * @todo none
 */

#include <stdio.h>
#include <stdlib.h>

enum{
        JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

enum{
        CAPRICORN = 19, AQUARIUS = 47, PISCES = 79, ARIES = 109,  TAURUS = 140,
        GEMINI = 171, CANCER = 203, LEO = 234, VIRGO = 265, LIBRA = 295,
        SCORPIO = 325, SAGITTARIUS = 355
};

struct date_t
{
        unsigned short day, month, year;
};


void signmenu(void);
void signpick(struct date_t *time);
void overflow_prevent(struct date_t *time, unsigned int max, int mod);
unsigned short normdays (struct date_t *time, unsigned short total);
void normsign(unsigned int total);
unsigned short leapdays (struct date_t *time, unsigned short total);
void leapsign(unsigned int total);


int main(void)
{
        signmenu();
        return 0;
} 


/**
 * The basic menu system for the program giving the user two options to either
 * enter a date or exit. If a non accepted value is given it will loop again.
 */
void signmenu(void)
{
        char buf[32];
        struct date_t time;
        printf("1. Find your sign\n2. Quit\nEnter a number: ");
        // This prevents the new line character from providing it's own input.
        error:
        fgets(buf, 32, stdin);
        
        //Uses the first character of buf as that's the only one that's read.
        switch (buf[0])
        {
        case '2':
                break;
        case '1':
                signpick(&time);
                signmenu();
                break;
        // if the program sees either a null or new line it asks for an input.
        case '\0':
        case '\n':
                goto error;
                break;

        default:
                printf("Unnaccepted value! Restarting...\n");
                signmenu();
                break;
        }
}






/**
 * Asks the user for a date and then proceeds to determine if it is a leap year
 * or a regular year. After that it then calls upon special functions for that.
 * @param time A struct which holds the date.
 */
void signpick(struct date_t *time)
{
        unsigned short total;
        printf("Enter a date yyyy-mm-dd: ");
        scanf("%hu-%hu-%hu", &time->year, &time->month, &time->day);
        overflow_prevent(time, DEC, 2);

        if ((time->year % 4 == 0 && time->year % 100 != 0) || 
        (time->year % 400 == 0)){
                total = leapdays(time, total);
                leapsign(total);
        } else {
                total = normdays(time, total);
                normsign(total);
        }

}


/**
 * Prevents a variable from being too large by using modulus.
 * @param subject variable in question that might be too large.
 * @param max the absolute limit the varaible can be.
 * @param mod if it is asking for the date or month again.
 * @return an adjusted version that is under the limit.
 */
void overflow_prevent(struct date_t *time, unsigned int max, int mod)
{
        if ((time->day > max || time->day == 0) && mod == 1){
                printf("Error the day %hu doesn't exist in current month"
                "in the year %hu. Enter a day with the limit %hu: ", time->day,
                time->year, max);
                scanf("%hu", &time->day);
                overflow_prevent(time, max, mod);
        } else if ((time->month > max || time->month == 0) && mod == 2){
                printf("Error, given month doesn't exist. Enter a new one: ");
                scanf("%hu", &time->month);
                overflow_prevent(time, max, mod);
        }
}

/**
 * Determines the current day it is in the year. First it uses the month
 * and then adds the current day it is to the total. After checking it
 * is a valid day. Checks for a regular year.
 * @param time The current date held as a struct.
 * @param total the total amount of days passed plus the current day.
 * @return total with the correct amount of days.
 */
unsigned short normdays(struct date_t *time, unsigned short total)
{       
        unsigned short max;
        
        switch (time->month)
        {
                case JAN:
                        total = 0;
                        max = 31;
                        break;
                case FEB:
                        total = 31;
                        max = 28;
                        break;
                case MAR:
                        total = 59;
                        max = 31;
                case APR:
                        total = 90;
                        max = 30;
                case MAY:
                        total = 120;
                        max = 31;
                        break;
                case JUN:
                        total = 151;
                        max = 30;
                        break;
                case JUL:
                        total = 181;
                        max = 31;
                        break;
                case AUG:
                        total = 212;
                        max = 31;
                        break;
                case SEP:
                        total = 243;
                        max = 30;
                        break;
                case OCT:
                        total = 273;
                        max = 31;
                        break;
                case NOV:
                        total = 304;
                        max = 30;
                        break;
                case DEC:
                        total = 334;
                        max = 31;
                        break;
                default:
                        break;
        }

        overflow_prevent(time, max, 1);
        return total + time->day;
}


/**
 * Determines the sign and prints out a statement with that sign. Using
 * enumerated values to make it more readable and easier to undestand.
 * @param total the amount of days passed. 
 */
void normsign(unsigned int total)
{
        if (total <= CAPRICORN){
                printf("Your sign is: Capricon\n");
        } else if (total <= AQUARIUS){
                printf("Your sign is: Aquarius\n");
        } else if (total <= PISCES){
                printf("Your sign is: Pisces\n");
        } else if (total <= ARIES){
                printf("Your sign is: Aries\n");
        } else if (total <= TAURUS){
                printf("Your sign is: Taurus\n");
        } else if (total <= GEMINI){
                printf("Your sign is: Gemini\n");
        } else if (total <= CANCER){
                printf("Your sign is: Cancer\n");
        } else if (total <= LEO){
                printf("Your sign is: Leo\n");
        } else if (total <= VIRGO){
                printf("Your sign is: Virgo\n");
        } else if (total <= LIBRA){
                printf("Your sign is: Libra\n");
        } else if (total <= SCORPIO){
                printf("Your sign is: Scorpio\n");
        } else if (total <= SAGITTARIUS){
                printf("Your sign is: Sagittarius\n");
        } else{
                printf("Your sign is: Capricon\n");
        }
}

/**
 * Determines the current day it is in the year. First it uses the month
 * and then adds the current day it is to the total. After checking it
 * is a valid day. Checks for a leap year.
 * @param time The current date held as a struct.
 * @param total the total amount of days passed plus the current day.
 * @return total with the correct amount of days.
 */
unsigned short leapdays (struct date_t *time, unsigned short total)
{       
        unsigned short max;

        switch (time->month)
        {
                case JAN:
                        total = 0;
                        max = 31;
                        break;
                case FEB:
                        total = 31;
                        max = 29;
                        break;
                case MAR:
                        total = 60;
                        max = 31;
                case APR:
                        total = 91;
                        max = 30;
                case MAY:
                        total = 121;
                        max = 31;
                        break;
                case JUN:
                        total = 152;
                        max = 30;
                        break;
                case JUL:
                        total = 182;
                        max = 31;
                        break;
                case AUG:
                        total = 213;
                        max = 31;
                        break;
                case SEP:
                        total = 244;
                        max = 30;
                        break;
                case OCT:
                        total = 274;
                        max = 31;
                        break;
                case NOV:
                        total = 305;
                        max = 30;
                        break;
                case DEC:
                        total = 335;
                        max = 31;
                        break;
                default:
                        break;
        }

        overflow_prevent(time, max, 1);
        return total + time->day;
}

/**
 * Determines the sign and prints out a statement with that sign. Using
 * enumerated values to make it more readable and easier to undestand. Similar
 * to the previous sign function but modified for leap years.
 * @param total the amount of days passed. 
 */
void leapsign(unsigned int total)
{
        if (total <= CAPRICORN){
                printf("Your sign is: Capricon\n");
        } else if (total <= AQUARIUS){
                printf("Your sign is: Aquarius\n");
        } else if (total <= 1 + PISCES){
                printf("Your sign is: Pisces\n");
        } else if (total <= 1 + ARIES){
                printf("Your sign is: Aries\n");
        } else if (total <= 1 + TAURUS){
                printf("Your sign is: Taurus\n");
        } else if (total <= 1 + GEMINI){
                printf("Your sign is: Gemini\n");
        } else if (total <= 1 + CANCER){
                printf("Your sign is: Cancer\n");
        } else if (total <= 1 + LEO){
                printf("Your sign is: Leo\n");
        } else if (total <= 1 + VIRGO){
                printf("Your sign is: Virgo\n");
        } else if (total <= 1 + LIBRA){
                printf("Your sign is: Libra\n");
        } else if (total <= 1 + SCORPIO){
                printf("Your sign is: Scorpio\n");
        } else if (total <= 1 + SAGITTARIUS){
                printf("Your sign is: Sagittarius\n");
        } else{
                printf("Your sign is: Capricon\n");
        }
}