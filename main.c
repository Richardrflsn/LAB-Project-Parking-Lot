#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

int parkType (char type[20],int hour){
    if (strcmp(type, "car") == 0)
    {
        return hour * 3000;
    } else if (strcmp(type, "bike") == 0)
    {
        return hour * 2000;
    }
    return hour; 
}

int main()
{
    int option;
    char choice2[10], vehicle[5][10], receipt[20] = {"Free Parking"};
    int entryTime[50], exitTime[50], total[50], totalTime[50];
    char name[20], numberPlate[20];
    bool choice[50];
    
    int i = 0, j;
    
    for (i = 0; i < 50; i++) {
        choice[i] = false;
	}
	
	i = 0;
	
    do
    {
        printf("\nParking Lot RRCB\n");
        printf("1. %15s\n", "normal parking");
        printf("2. %13s\n", "Subscription");
        printf("3. %8s\n", "Receipt");
        printf("4. %5s\n", "Exit");
        printf("Input options : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("transportation type(Car/Bike): ");
            scanf("%s", vehicle[i]);
            if (strcmp(vehicle[i], "car") == 0)
            {
            }
            else if (strcmp(vehicle[i], "bike") == 0)
            {
            }
            else
            {
                break;
            }
            printf("\nParking Price\n");
            printf("Input entry hour : ");
            scanf("%d", &entryTime[i]);
            printf("Input exit hour : ");
            scanf("%d", &exitTime[i]);

            if (exitTime[i] >= entryTime[i]) {     
                totalTime[i] = exitTime[i] - entryTime[i];
            }
            else {
                totalTime[i] = (24 - entryTime[i]) + exitTime[i];
            }

            printf("\n"); 
            total[i] = parkType(vehicle[i], totalTime[i]);
            printf("Intotal: %d\n", total[i]);
            i++;
            break;
        case 2:
            printf("\nSubscription\n");
            printf("Yes/No\n");
            printf("Choice: ");
            scanf("%s", choice2);
            if (strcmp(choice2, "yes") == 0)
            {
                printf("\nFree parking\n");
                choice[i - 1] = true;
            } else {
                printf("Create subscription\n");
                printf("Yes/No\n");
                printf("Choice: ");
                scanf("%s", choice2);
                FILE* file = fopen("database.txt", "w");
                if (strcmp(choice2, "yes") == 0)
                {
                    printf("Enter your name: ");
                    fscanf(stdin, "%s", name);
                    printf("Enter your number plate: ");
                    fscanf(stdin, "%s", numberPlate);
                    fprintf(file, "%s\n%s\n", name, numberPlate);
                    fclose(file);
                    choice[i - 1] = true;
                    
                } else {
                    printf("Please pay!!\n");
                    choice[i - 1] = false;
                }
            }
            break;
        case 3:
            for (j = 0; j < i; j++) {

                printf("\nParking Receipt Num-%d\n", (j + 1));
                printf("\nParking Lot RRCB\n");
                printf("-----------------------------------------\n");
                printf("Type vehicle        : %s\n", vehicle[j]);
                printf("Entry hour          : %d\n", entryTime[j]);
                printf("Exit hour           : %d\n", exitTime[j]);
                printf("Total               : %d\n", total[j]);
                if(choice[j] == true)
                {
                    printf("%25s\n", receipt);
                }
                printf("-----------------------------------------\n");
}
            
            break;
        case 4:
            printf("\nThank you, have a nice day!\n");
            break;
        
        default:
            printf("No options!\n");
            break;
        }
    } while (option != 4);
    
    return 0;
}