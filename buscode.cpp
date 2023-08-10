#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
using namespace std;

char ch[10][130] = {"CHN-BLR Express", "CHN - HYD Express", "CHN-VIZAG Express", "CHN-KOCHIN Express", "CHN-PDY Express", "CHN-CJB Express"};
char name[32][100] = {'\0'};
int num1[32] = {};
int trno;

void bus();
void name_number(int booking, char numstr[100]);
void booking();
void read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancel();
void login();

int main()
{
    login();
    int num, i;
    int num1[32][32] = {}; // 
    do
    {
        system("cls");

        cout << "\n\n\n";
        cout << "====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n";
        cout << "\t\t\t\t\t[1]=> View Bus List\n";
        cout << "\n";
        cout << "\t\t\t\t\t[2]=> Book Tickets\n";
        cout << "\n";
        cout << "\t\t\t\t\t[3]=> Cancel Booking\n";
        cout << "\n";
        cout << "\t\t\t\t\t[4]=> Bus Status Board\n";
        cout << "\n";
        cout << "\t\t\t\t\t[5]=> Exit\n\n";
        cout << "===============================================================================================================\n\n";
        cout << "\t\t\tEnter Your Choice:: ";
        cin >> num;

        switch (num)
        {
        case 1:
            bus();
            break;
        case 2:
            booking();
            break;
        case 3:
            cancel();
            break;
        case 4:
            status();
            break;
        }

        getch();
    } while (num != 5);

    system("CLS");
    cout << "\t----------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n";
    cout << "\t----------------------------------------------------------------------------------------------------------\n";
    getch();
    return 0;
}
void booking()
{
    int i = 0;
    char numstr[100];
    system("cls");
    std::cout << "=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";
    bus();
    std::cout << "Enter the Bus number:--->";
    std::cin >> trno;
    std::cout << "=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";
    std::cout << "Your Bus Number is " << trno << " ********** " << ch[trno - 1];
    status_1(trno);

    FILE *f1;
    char str1[80] = "32";
    int seat1, booking = 0;

    if (trno >= 1 && trno <= 5)
    {
        f1 = fopen(("tr" + std::to_string(trno) + ".txt").c_str(), "r+");
        if (f1)
        {
            fgets(str1, 80, f1);
            fclose(f1);
        }
    }

    seat1 = atoi(str1);

    if (seat1 <= 0)
    {
        std::cout << "There is no blank seat in this bus ";
    }
    else
    {
        std::cout << "\n\n\n\t\t\t\tAvailable Seats:------>" << seat1 << "\n";
        std::cout << "\n\t\t\t\tNumber of Tickets:-----> (max 5 at a time)";
        std::cin >> booking;
        std::cout << "\n";

        seat1 -= booking;

        itoa(trno, numstr, 10);
        name_number(booking, numstr);

        std::cout << "\n\t\t\t\tThe Total booking amount is " << 200 * booking;
        itoa(seat1, str1, 10);

        if (trno >= 1 && trno <= 5)
        {
            f1 = fopen(("tr" + std::to_string(trno) + ".txt").c_str(), "w");
            if (f1)
            {
                fputs(str1, f1);
                fclose(f1);
            }
        }
    }
}

void bus()
{
    cout << "\n\n\n";
    cout << "=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";

    for (int i = 0; i < 6; i++)
    {
        cout << "\t\t\t\t\t[" << i + 1 << "]  =>  " << ch[i] << "\n";
        cout << "\n";
    }
}

void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
    int number;
    FILE *a, *b;
    int i = 0;
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    a = fopen(tempstr1, "a");
    b = fopen(tempstr2, "a");
    for (i = 0; i < booking; i++)
    {
        cout << "============================Enter the details for ticket no " << i + 1 << "============================\n\n\n";
        cout << "\t\t\t\tEnter the seat number:--->";
        cin >> number;
        cout << "\t\t\t\tEnter the name of person:--->";
        cin >> name[number - 1];
        cout << "\n======================================================================================================\n\n";
        cout << "\n";
        itoa(number, tempstr, 10);
        fprintf(a, "%s ", name[number - 1]);
        fprintf(b, "%s ", tempstr);
    }
    fclose(a);
    fclose(b);
}

void read_number(int trno)
{
    char tempstr2[15] = "number";
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);

    FILE *a = fopen(tempstr2, "r"); // Open the number file for reading
    if (a == NULL)
    {
        perror("Error opening number file");
        exit(1);
    }

    while (fscanf(a, "%d", &num1[i]) == 1)
    {
        i++;
    }

    k = i;

    fclose(a);
}

void read_name(int trno)
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "a+");
    while (!feof(b))
    {
        name[i][j] = fgetc(b);

        if (name[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}

void status()
{
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int trno, index = 0, j;
    printf("Enter the number of bus:---->");
    scanf("%d", &trno);
    read_number(trno); // Calling the function to read seat numbers
    read_name(trno);   // Reading the booking details
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n", trno, ch[trno - 1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (int i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (int j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

    void status_1(int trno)
    {
        printf("Your Bus Number is %d ********** %s\n", trno, ch[trno - 1]);
        printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
        int i, index = 0, j;
        read_number(trno); // Calling the function to read seat numbers
        read_name(trno);   // Reading the booking details
        char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
        for (i = 0; i < j; i++)
        {
            strcpy(tempname[num1[i]], name[i]);
        }
        for (i = 0; i < 8; i++)
        {
            printf("\t\t\t\t");
            for (j = 0; j < 4; j++)
            {
                printf("%d.%s\t", index + 1, tempname[index + 1]);
                index++;
            }
            printf("\n");
        }
    }

    void cancel()
    {
        int seat_no, i, j;
        char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
        cout << "Enter the bus number:---->";
        cin >> trno;
        itoa(trno, numstr, 10);
        strcat(numstr, ".txt");
        strcat(tempstr1, numstr);
        strcat(tempstr2, numstr);
        read_number(trno);
        read_name(trno);
        status_1(trno);
        cout << "Enter the seat number:--->";
        cin >> seat_no;
        FILE *a, *b;
        a = fopen(tempstr1, "w+");
        b = fopen(tempstr2, "w+");
        for (i = 0; i < 32; i++)
        {
            if (num1[i] == seat_no)
            {
                for (j = 0; j < 32; j++)
                {
                    if (num1[j] != seat_no && num1[j] != 0)
                    {
                        fprintf(b, "%d ", num1[j]);
                        fprintf(a, "%s", name[j]);
                    }
                    else if (num1[j] == seat_no && num1[j] != 0)
                    {
                        strcpy(name[j], "Empty ");
                    }
                }
            }
        }
        fclose(a);
        fclose(b);
        cout << "\n\n";
        cout << "======================================================================================================\n";
        cout << "\t\t\t\t Your refund amount will be credited to your account  within 3-5 business days\t\t\t\n";
        cout << "======================================================================================================\n";
    }

    void login()
    {
        int attempts = 0;
        char username[10];
        char password[10];

        cout << "========================= LOGIN FORM =========================\n";

        while (attempts < 3)
        {
            cout << "Enter USERNAME: ";
            cin >> username;

            cout << "Enter PASSWORD: ";
            cin >> password;

            if (strcmp(username, "user") == 0 && strcmp(password, "pass") == 0)
            {
                cout << "\nWELCOME TO OUR BUS RESERVATION SYSTEM! LOGIN IS SUCCESSFUL\n";
                cout << "Press any key to continue...";
                getch();
                return;
            }
            else
            {
                attempts++;
                cout << "\nSORRY! LOGIN IS UNSUCCESSFUL\n";
                cout << "Remaining attempts: " << 3 - attempts << "\n";
                getch();
                system("cls");
            }
        }

        cout << "\nSorry, you have exceeded the maximum number of login attempts.\n";
        cout << "Press any key to exit...";
        getch();
        exit(0);
    }
