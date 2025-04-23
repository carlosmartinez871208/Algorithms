#include <stdlib.h>
#include <stdio.h>

#define SECONDS_SCALER              (6)
#define MINUTES_SCALER              (6)
#define HOURS_SCALER                (30)
#define MINUTES_SECONDS_SCALER      (0.1)
#define HOURS_MINUTES_SCALER        (0.5)
#define HOURS_SECONDS_SCALER        (0.008333)

#define CLOCK_ABSOLUTE              (360)

static void clock_hands_angle (uint8_t hours,uint8_t minutes,uint8_t seconds);

int main(void)
{
    printf("This program gives the clock hands angle: \r\n");
    clock_hands_angle (6,00,00);
    return 0;
}

/* Algorithm: Calculate hands clock angles between each others.
    Analysis:
        Full clock is 12 hours, it means 12 hours -> 360 degrees. So, the rate by hour will be: (1 hours * 360 degrees)/12 hours = 30 degrees. Therefore: 1 hour is equivalent to 30 degrees.
        Full hour has 60 minutes, it means 60 minutes -> 360 degrees. So, the rate by minute will be: (1 minutes * 360 degrees)/60 minutes = 6 degrees. Therefore: 1 minute is equivalent to 6 degrees.
        Full minute has 60 seconds, it means 60 seconds -> 360 degrees. So, the rate by seconds will be: (1 seconds * 360 degrees)/60 seconds = 6 degrees. Therefore 1 seconds is equivalente to 6 degrees.

        So, 1 hours -> 30 degrees, then 30 degrees -> 60 minutes. Then, (1 minute * 30 degrees)/60 minutes = 0.5 degrees. Therefore: every minute will generate a 0.5 degrees step in the hour hand.
        So, 1 minute -> 0.5 degrees, then 0.5 degrees -> 60 seconds. Then, (1 second * 0.5 degrees)/60 seconds = 1/120 degrees = 0.00833 degrees. Therefore: every second will generate a 0.00833 degrees step in the hour hand.

        So, 1 minute -> 6 degrees, then 6 degrees -> 60 seconds. Then, (1 second * 6 degrees)/60 seconds = 1/10 degrees = 0.1 degrees. Therefore: every second will generate a 0.1 degree step in the minutes hand.

        Note: 1 second -> 6 degrees. 

        seconds_scaler        = 6;
        minutes_scaler        = 6;
        hours_scaler           = 30;
        minute_seconds_scaler = 0.1;
        hours_minutes_scaler  = 0.5;
        hours_seconds_scaler  = 0.00083;

        seconds_angle = (seconds*seconds_scaler)                                                                  = (seconds * 6);
        minutes_angle = (minutes*minutes_scaler) + (seconds*seconds_minute_scaler)                                = (minutes * 6) + (seconds * 0.1);
        hour_angle    = (hours*hours_scaler) + (minutes*hours_minutes_scaler) + (seconds*hours_seconds_scaler)    = (hours * 30) + (minutes * 0.5) + (seconds * 0.00833)

            i.e. 12:00:00 or 00:00:00
                0       degrees hours hand,   0   degrees minutes hand,   0 degrees seconds hand. Angle hour-minute =   0      degrees, angle hour-seconds =    0       degrees, angle minutes-seconds =.  0   degrees.
            i.e. 12:00:01 or 00:00:01
                0.00833 degrees hours hand,   0.1 degrees minutes hand,   6 degrees seconds hand. Angle hour-minute =   0.09167 degrees, angle hour-seconds =   5.99167 degrees, angle minutes-seconds =   5.9 degrees.
            i.e. 12:00:59 or 00.00:59
                0.49167 degress hours hand,   5.9 degrees minutes hand, 354 degrees seconds hand. Angle hour-minute =   5.40833 degrees, angle hour-seconds = 353.50833 degrees, angle minutes-seconds = 348.1 degress.
            i.e. 12:01:00 or 00:00:00
                0.5     degrees hours hand,   6   degrees minutes hand,   0 degrees seconds hand. Angle hour-minute =   5.5     degrees, angle hour-seconds =   0.5     degrees, angle minutes-seconds =   6   degrees.
            i.e. 12:01:01 or 00:01:01
                0.50833 degrees hours hand,   6.1 degrees minutes hand,   6 degrees seconds hand. Angle hour-minute =   5.59167 degrees, angle hour-seconds =   5.49167 degrees, angle minutes-seconds =   0.1 degress.
            i.e. 12:59:59 or 00:59:59
               29.99147 degrees hours hand, 359.9 degrees minutes hand, 354 degrees seconds hand. Angle hour-minute = 329.90853 degrees, angle hour-seconds = 324.00853 degrees, angle minutes-seconds =   5.9 degrees 
*/

void clock_hands_angle (uint8_t hours,uint8_t minutes,uint8_t seconds)
{
    float seconds_angle         = 0.0;
    float minutes_angle         = 0.0;
    float hours_angle           = 0.0;
    float angle_hours_minutes   = 0.0;
    float angle_hours_seconds   = 0.0;
    float angle_minutes_seconds = 0.0;
    if(0<=hours && hours<12)
    {
        if(0<=minutes && 60>=minutes)
        {
            if(0<=minutes && 60>=minutes)
            {
                seconds_angle = ((float)seconds*SECONDS_SCALER);
                minutes_angle = ((float)minutes)*MINUTES_SCALER + ((float)seconds*MINUTES_SECONDS_SCALER);
                hours_angle   = ((float)hours*HOURS_SCALER)+((float)minutes)*HOURS_MINUTES_SCALER + ((float)seconds*HOURS_SECONDS_SCALER);
                if(hours_angle >= minutes_angle)
                {
                    angle_hours_minutes = hours_angle - minutes_angle;
                }
                else
                {
                    angle_hours_minutes = minutes_angle - hours_angle;
                }
                if(hours_angle >= seconds_angle)
                {
                    angle_hours_seconds = hours_angle - seconds_angle;
                }
                else
                {
                    angle_hours_seconds = seconds_angle - hours_angle;
                }
                if(minutes_angle >= seconds_angle)
                {
                    angle_minutes_seconds = minutes_angle - seconds_angle;
                }
                else
                {
                    angle_minutes_seconds = seconds_angle - minutes_angle;
                }
                printf("Angle hours vs minutes  : %.5f or ",angle_hours_minutes);
                angle_hours_minutes = CLOCK_ABSOLUTE - angle_hours_minutes;
                printf("%.5f\n\r",angle_hours_minutes);
                printf("Angle hours vs seconds  : %.5f or ",angle_hours_seconds);
                angle_hours_seconds = CLOCK_ABSOLUTE - angle_hours_seconds;
                printf("%.5f\n\r",angle_hours_seconds);
                printf("Angle minutes vs seconds: %.5f or ",angle_minutes_seconds);
                angle_minutes_seconds = CLOCK_ABSOLUTE - angle_minutes_seconds;
                printf("%.5f\n\r",angle_minutes_seconds);
            }
            else
            {
                printf("Error: seconds format 0 to 60\r\n");
            }
        }
        else
        {
            printf("Error: minutes format 0 to 60\r\n");
        }
    }
    else
    {
        printf("Error: hours format 0 to 11\r\n");
    }
}