/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5  //  max number of rooms



// Function prototypes
void initializeSystem(int room_count,int lights[],int temp[],int motion[],int locks[]);
void displayMenu();
void controlLights(int  room_count,int lights[], int light_on_count[]);
void readTemperature(int room_count,int temp[]);
void detectMotion(int room_count,int motion[],int locks[],int no_motion_count[]);
void securitySystem(int room_count,int locks[]);
void analyzeHouseStatus(int room_count,int lights[],int temp[],int motion[],int locks[]);

int main() {

    int room_count; 
    // get room input
    printf("Enter the number of rooms: ");
    scanf("%d",&room_count);

    if(room_count < 1 || room_count > MAX_ROOMS)
    {
        printf("Invalid input! Enter a value between 1 and %d.\n", MAX_ROOMS);
        return 1;
    }

    // Array initialize
    int lights[room_count],temp[room_count],motion[room_count],locks[room_count];
    int no_motion_count[1] = {0};
    int light_on_count[1] = {0};


    // Initializing all devices for given rooms
    initializeSystem(room_count,lights,temp,motion,locks);

    int choice;
    
    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
            controlLights(room_count,lights,light_on_count);
            break;
        
        case 2: 
            readTemperature(room_count,temp);
            break;

        case 3: 
            detectMotion(room_count,motion,no_motion_count,locks);
            break;

        case 4: 
            securitySystem(room_count,locks);
            break;

        case 5: 
            analyzeHouseStatus(room_count,lights,temp,motion,locks);
            break;

        case 6:
            printf("Exiting system...!\n");
            return 0;
        
        default:
            printf("Invalid choice! Try Again\n");
        }
        
    }
    
    return 0;
}

 
void initializeSystem(int room_count,int lights[],int temp[],int motion[],int locks[]) {

    for(int i=0;i < room_count; i++){
        lights[i] = 0;
        temp[i] = (rand() % 16) + 20;
        motion[i] = 0;
        locks[i] = 1;
    }
    printf("Initializing System...\n");

}

void displayMenu() {

    printf("\n====SMART HOME MENU====\n");
    printf("1. Toggle light\n");
    printf("2. Read temperature\n");
    printf("3. Check motion sensor\n");
    printf("4. Lock/unlock security system\n");
    printf("5. House status summary\n");
    printf("6. Exit\n");
}

void controlLights(int  room_count,int lights[], int light_on_count[]) {
    //Enter room number to toggle light (1-3): 2  
    //Light in Room 2 is now ON.  
    int room_no;
    printf("Enter room number to toggle light (1 to %d)", room_count);
    scanf("%d",&room_no);

    if (room_no >= 1 && room_no <= room_count)
    {
        lights[room_no - 1] = 1 - lights[room_no - 1];//toggle light
        printf("Light in Room %d is now %s",room_no,(lights[room_no - 1] ? "ON" : "OFF"));
    }
    else{
        printf("Invalid room number !");
    }

    int allLightsOn = 1;
    for(int i = 0; i < room_count;i++){
        if (lights[i] == 0) {
            allLightsOn = 0;
            break;
        }
    }

    if (allLightsOn) {
        light_on_count[0]++;
    }
    else{
        light_on_count[0] = 0;
    }

    if (light_on_count[0] >= 5) {
        printf("All lights are ON for too long. Consider turning OFF to save energy!\n");
        light_on_count[0] = 0;

    }
}

void readTemperature(int room_count,int temp[]) {

    int room_no;
    printf("Enter room number to check temperature (1 to %d)", room_count);
    scanf("%d",&room_no);

    if (room_no >= 1 && room_no <= room_count)
    {
        printf("Temperature in Room %d is %d degree Celsius.\n",room_no,temp[room_no - 1]);
    }
    else{
        printf("Invalid room number !");
    }

}
void detectMotion(int room_count,int motion[],int locks[],int no_motion_count[]) {

    int room_no;
    printf("Enter room number to check motion (1 to %d)", room_count);
    scanf("%d",&room_no);

    if (room_no < 1 || room_no > room_count) {
        printf("Invalid room number!\n");
        return;
    }

    motion[room_no - 1] = 1 - motion[room_no - 1];
    if (motion[room_no - 1] == 1){
        printf("Motion Detected in Room %d.\n",room_no);
        no_motion_count[0] = 0;
    }
    else{
        printf("No Motion Detected in Room %d.\n",room_no);
        no_motion_count[0]++;
    }

    if(no_motion_count[0] >= 5){
        for(int i = 0;i < room_count; i++)
        {
            locks[i] = 1;
        }
        printf("No motion detected for a while. Auto locking all doors!\n");
        no_motion_count[0] = 0;
    }
}

void securitySystem(int room_count,int locks[]) {

    int room_no;
    printf("Enter room number to toggle light (1 to %d)", room_count);
    scanf("%d",&room_no);

    if (room_no >= 1 && room_no <= room_count)
    {
        locks[room_no - 1] = 1 - locks[room_no - 1];//toggle light
        printf("Light in Room %d is now %s",room_no,(locks[room_no - 1] ? "Locked" : "Unlocked"));
    }
    else{
        printf("Invalid room number !");
    }

}
void analyzeHouseStatus(int room_count,int lights[],int temp[],int motion[],int locks[]) {

    printf("\n=====House Status ====\n");
    for (int i = 0; i < room_count;i++)
    {
        printf("Room %d: Light %s, Temp %d degree celcius, Motion %s, %s\n",i+1,lights[i] ? "ON" : "OFF",temp[i],motion[i] ? "Detected" : "Not Detected",locks[i] ? "Locked" : "Unlocked");
        if(temp[i] > 30) {
            printf("Warning High temperature in Room: %d (%d degree celsius)\n",i+1,temp[i]);
        }
    }

}

