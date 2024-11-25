#include <stdio.h>

#define DAYS 7

int main() {
    int startHours[DAYS];
    int startMinutes[DAYS];
    int endHours[DAYS];
    int endMinutes[DAYS];
    int hours[DAYS];
    int minutes[DAYS];
    float wages[DAYS];


    int totalHours   = 0;
    int totalMinutes = 0;
    float totalWages = 0;

    int daysWorked;
    float payPerHour;

    int i;


    // Gathers days worked and pay per hour
    printf("Days worked : ");
        scanf("%d",&daysWorked);
    printf("\nPay per hour: ");
        scanf("%f",&payPerHour);

    // Gathers the time user went and left work each day
    for (i=0; i<daysWorked; i++) {;
        printf("Start hrs  for Day %d: ",i+1);
            scanf("%d",&startHours[i]);
        printf("Start mins for Day %d: ",i+1);
            scanf("%d",&startMinutes[i]);
        printf("End   hrs  for Day %d: ",i+1);
            scanf("%d",&endHours[i]);
        printf("End   mins for Day %d: ",i+1);
            scanf("%d",&endMinutes[i]);   
        printf("\n"); 
    }

    // Calculates the amount of hours and minutes worked
    for (i=0; i<daysWorked; i++) {
    // condition 1 (startMinutes < endMinutes)  
        if (endMinutes[i] > startMinutes[i]) {
            hours[i]   = endHours[i] - startHours[i];
            minutes[i] = endMinutes[i] - startMinutes[i];
        }
    // condition 2 (startMinutes > endMinutes)
        else if (startMinutes[i] > endMinutes[i]) {
            hours[i]   = endHours[i] - startHours[i] + 1;
            minutes[i] = (60-startMinutes[i]) + endMinutes[i];
        }
    // condition 3 (startMinutes == endMinutes)
        else {
            hours[i] = endHours[i] - startHours[i];
        }
    }


    // Calculates wages
    // wage = (hours+(minutes/60)) * payPerHour
    for (i=0; i<daysWorked; i++) {
        wages[i] = (hours[i] + (minutes[i]/60)) * payPerHour;
    }
    

    
    // Displays table of results
    printf("\n----------------------------------------------------------");
    printf("\nDay  Start   End     Hours    TotalHr   Wages    TotalWages\n");

    for (i=0; i<daysWorked; i++) {
        totalHours   += hours[i];
        totalMinutes += minutes[i];
        totalWages   += wages[i];
        
        printf("%d    ",i+1);
        printf("%02d:%02d   ",startHours[i],startMinutes[i]);
        printf("%02d:%02d   ",endHours[i],endMinutes[i]);
        printf("%02dh%02dm    ",hours[i],minutes[i]);
        printf("%02dh%02dm    ",totalHours,totalMinutes);
        printf("%03.4f   ",wages[i]);
        printf("%03.4f",totalWages);
        printf("\n");
    }

    return 0;
}
