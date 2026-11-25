// ================================================
// Bank Management System
// Developed in C Language
// Features:
// 1. Admin Mode  -> Add accounts / Display accounts
// 2. Customer Mode -> Deposit / Withdraw / Check balance
// 3. File handling for saving/loading data
// ================================================

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Structure to store account information
struct Acount{
    char name[50];
    char password[7];   // 6 digits + null character
    float amount;
    int id;
};

// Function prototypes
int checkPassword(char p[],char password[]);
int verify(struct Acount acount[],int n);
int addAcount(struct Acount acount[],int n);
void checkBalance(struct Acount acount[],int n);
void deposit(struct Acount acount[],int n);
void withdraw(struct Acount acount[],int n);
void displayAllAcount(struct Acount acount[],int n);
bool Exit();

// ==================================================
// Function to save all accounts into file
// ==================================================
void keepData(struct Acount acount[], int n){
    FILE *fptr;
    
    fptr = fopen("Data.txt","w"); // Open file in write mode
    
    if(fptr == NULL){
        printf("File not found!\n");
        return;
    }

    // Save each account into file
    for(int i = 0 ; i < n ; i++){
        fprintf(fptr,"%d,%s,%.2f,%s\n",acount[i].id,acount[i].name,acount[i].amount,acount[i].password);    
    }

    fclose(fptr); // Close file
}
// ==================================================
// Function to load accounts from file
// ==================================================
void collectData(struct Acount acount[],int *n){
    FILE *fptr;

    fptr = fopen("Data.txt","r");   // Open file in read mode

    if(fptr == NULL){
        printf("File not found!\n");
        return;
    }
    
    // Read file line by line
    while(fscanf(fptr,"%d,%49[^,],%f,%6s\n",&acount[*n].id,acount[*n].name,&acount[*n].amount,acount[*n].password) == 4){
        (*n)++;
    }


    
    fclose(fptr);  // Close file
} 
// ==================================================
// Main Function
// ==================================================  
int main(){

    struct Acount acount[50];
    int numberofAcount= 0;
    int option;
    int mode;
    bool x = true;

    // Load saved accounts from file
    collectData(acount,&numberofAcount);
    printf("Loaded acount ... : %d\n",numberofAcount);

    do{         
            system("cls");
                printf(" ==============================\n");
                printf(" =         Bank System        =\n");
                printf(" ==============================\n");
            printf("1- Admin \n");
            printf("2- Customer \n");
            printf("Enter the number of the mode :");
            scanf("%d",&mode);

            if(mode == 1){
                // ================= ADMIN MODE =================
                system("cls");
                printf(" ========================\n");
                printf(" =         Admin        =\n");
                printf(" ========================\n");
                printf("1- Add new acount \n");
                printf("2- displayAllAcount \n");
                printf("3- Exit \n");
                printf("Enter the number of the operation :");
                scanf("%d",&option);

                switch (option)
                {
                case  1:
                    system("cls");
                    // Add new account
                    if(addAcount(acount,numberofAcount) == 1){
                        numberofAcount ++;
                        keepData(acount,numberofAcount);
                    }
                    system("pause");
                    break;
                case  2:
                    system("cls");
                    displayAllAcount(acount,numberofAcount);
                    system("pause");
                    break;
                case  3:
                    x = Exit();
                    break;
                default:
                    printf("Invalid option");
                    system("pause");
                    break;
                }
            }
            else{
                // ================= CUSTOMER MODE =================
                system("cls");
                printf(" ========================\n");
                printf(" =       Customer       =\n");
                printf(" ========================\n");
                printf("1- Deposit \n");
                printf("2- Withdraw \n");
                printf("3- Check Balance \n");
                printf("4- Exit \n");
                printf("Enter the number of the operation :");
                scanf("%d",&option);
    
                switch (option)
                {
    
                    case  1:
                        system("cls");
                        deposit(acount,numberofAcount);
                        system("pause");
                        break;
                    case  2:
                        system("cls");
                        withdraw(acount,numberofAcount);
                        system("pause");
                        break;
                    case  3:
                        system("cls");
                        checkBalance(acount,numberofAcount);
                        system("pause");
                        break;
                    case  4:
                        x = Exit();
                        break;
                    default:
                        printf("Invalid option");
                        system("pause");
                        break;
                }
            }
            
    }while(x);

    
    // Save data before closing
    keepData(acount,numberofAcount);
    return 0;
}
// ==================================================
// Check if entered password matches real password
// ==================================================
int checkPassword(char p[],char password[]){
    int correct = 0;
    for(int i = 0 ; i < 6 ; i++){
        if(p[i] == password[i]){
            correct++;
        }
    }
    return correct == 6 ? 1 : 0;
}
// ==================================================
// Verify account ID and password
// ==================================================
int verify(struct Acount acount[],int n){
    int id;
    char p[7];
    printf("Enter your acount id : ");
    scanf("%d",&id);
    if(id > 0 &&id <= n){
        printf("Enter your password : ");
        scanf("%s", p);
        if(checkPassword(p, acount[id-1].password) == 1){
            return id-1;   // Return account index
        }
        else{
            printf("Password is wrong!!\n");
        }
    }
    else{
        printf("NO ACOUNT WITH THIS ID  !!\n"); 
    }

    return -1;
}
// ==================================================
// Add New Account
// ==================================================
int addAcount(struct Acount acount[],int n){
    int chance = 1;

    if(n >= 50){
        printf("The Bank system is full!!\n");
        return 0;
    }

    printf("==========NEW ACOUNT=========\n");
    printf("Enter your name : ");
    scanf("%s", acount[n].name);

    printf("Enter your first amount :");
    scanf("%f",&acount[n].amount);

    if(acount[n].amount < 0){
        printf("Invalid amount!\n");
        return 0;
    }

    while(chance <= 3){

        printf("Initiate your password(6 digit) : ");
        scanf("%s", acount[n].password);
    
        // Check password length
        if(strlen(acount[n].password) != 6){
            printf("Password must be 6 digits!!,,please try again\n");
            chance++;
            continue;
        }
       
        int valid = 1;
        // Check digits only
                for(int i = 0 ; i < 6 ; i++){
                    if(acount[n].password[i] < '0' || acount[n].password[i] > '9'){
                    valid = 0;
                    break;                    
                    }
                }

        if(valid){
            acount[n].id = n + 1;
            printf("Account created successfully!\n");
            printf("===================\n");
            return 1;
        }
        else{
            printf("Password must be digits only!!,,please try again\n");
            chance++;
        }
                
        
    }
    

    printf("Too many failed attempts. Account not created.\n");
    printf("===================\n"); 
    return 0;
}
// ==================================================
// Show balance after verification
// ==================================================
void checkBalance(struct Acount acount[],int n){
    printf("========Display========\n");
    int index = verify(acount,n);

    if(index == -1 ) return ;

    printf("ID : %d\n",acount[index].id);
    printf("NAME : %s\n",acount[index].name);
    printf("AMOUNT : %f\n",acount[index].amount);
    printf("===================\n"); 
}
// ==================================================
// Deposit money
// ==================================================
void deposit(struct Acount acount[],int n){
    printf("======Deposit======\n");
    float a;
    int index = verify(acount,n);

    if(index == -1 ) return ;

    printf("please Enter your deposit amount: ");
    scanf("%f",&a);

        if(a <= 0){
        printf("Invalid amount!\n");
        return;
        }
    acount[index].amount += a;  
    keepData(acount,n);
    printf("Deposit operation is done successfully!\n");
    printf("===================\n"); 
}
// ==================================================
// Withdraw money
// ==================================================
void withdraw(struct Acount acount[],int n){
    printf("======Withdraw======\n");
    float a;
    int index = verify(acount,n);
    if(index == -1 ) return ;

    if(acount[index].amount <= 0){
        printf("NO MONEY IN YOUR ACOUNT!!\n");
        return;
    }
    printf("please Enter your withdraw amount: ");
    scanf("%f",&a);

        if(a <= 0){
        printf("Invalid amount!\n");
        printf("===================\n"); 
        return;
        }

    
    if(a > acount[index].amount)
        printf("No ENOUGH MONEY IN YOU ACOUNT!!\n");
    else{
        acount[index].amount -= a;
        keepData(acount,n);
        printf("Withdraw operation is done successfully!\n");
    }

    printf("===================\n"); 

}
// ==================================================
// Display all accounts (Admin only)
// ==================================================
void displayAllAcount(struct Acount acount[],int n){
    printf("======displayAllAcount======\n");
        printf("id      name        amount\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d      %s        %.2f\n",acount[i].id,acount[i].name,acount[i].amount);
    }
    printf("===================\n"); 
}
// ==================================================
// Exit Function
// ==================================================
bool Exit(){
            char exit;
            printf("Enter X or x to close the program : ");
            scanf(" %c",&exit);
            return (exit == 'X' || exit == 'x')? false : true;
}