#include <stdio.h>
#include <math.h>

void printmenu();
void emi();
void fdtdr();
void fdstdr();
void recurring();
void scss();
void kvp();

void main()
{
    int ch;

    while(ch != 7)
    {
        printmenu();
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                emi();
                break;
            case 2:
                fdtdr();
                break;
            case 3:
                fdstdr();
                break;
            case 4:
                recurring();
                break;
            case 5:
                scss();
                break;
            case 6:
                kvp();
                break;
            case 7:
                printf("Exit");
                break;
            default:
                printf("Invalid Choice!");
                break;
        }
        printf("\n-----------------------------\n");
    }

}
void printmenu()
{
    printf("\n----- FINANCIAL CALCULATOR -----\n");
    printf("\n1. EMI BASIC");
    printf("\n2. FIXED DEPOSIT-TDR");
    printf("\n3. FIXED DEPOSITE-STDR");
    printf("\n4. RECURRING DEPOSITE");
    printf("\n5. SENIOR CITIZEN SAVING SCHEME");
    printf("\n6. KISAN VIKAS PATRA");
    printf("\n7. PRESS 7 TO EXIT !\n");
    printf("\n--------------------------------\n");
}
void emi()
{
    float LA, AI;
    int ch, year;

    float monthlyRate, emiValue, totalPaid, interestPaid;
    printf("\n----- EMI CALCULATOR -----\n\n");
    printf("Enter the Loan Amount : ");
    scanf("%f", &LA);

    printf("Enter Annual Interest Rate (in%%) : ");
    scanf("%f", &AI);

    printf("\n1. Yearly");
    printf("\n2. Monthly\n");

    printf("\nEnter your choice (1-2) : ");
    scanf("%d", &ch);

    if (ch == 1)
    {
        printf("Enter Loan Term in Years : ");
        scanf("%d", &year);
    }
    else if (ch == 2)
    {
        printf("Enter Loan Term in Months : ");
        scanf("%d", &year);
    }
    else
    {
        printf("Invalid Choice!");
        return;
    }

    monthlyRate = AI / (12 * 100);

    if (ch == 1)
    {
        int months = year * 12;

        emiValue = (LA * monthlyRate * pow(1 + monthlyRate, months)) /
                   (pow(1 + monthlyRate, months) - 1);

        totalPaid = emiValue * months;
        interestPaid = totalPaid - LA;

        printf("\n----- EMI YEARLY -----\n");
        printf("\nMonthly EMI = %.2f", emiValue);
        printf("\nPrincipal Amount = %.2f", LA);
        printf("\nInterest Paid = %.2f", interestPaid);
        printf("\nTotal Repayment = %.2f", totalPaid);
    }

    else if (ch == 2)
    {
        emiValue = (LA * monthlyRate * pow(1 + monthlyRate, year)) /
                   (pow(1 + monthlyRate, year) - 1);

        totalPaid = emiValue * year;
        interestPaid = totalPaid - LA;

        printf("\n----- EMI MONTHLY -----\n");
        printf("\nMonthly EMI = %.2f", emiValue);
        printf("\nPrincipal Amount = %.2f", LA);
        printf("\nTotal Amount Paid = %.2f", totalPaid);
        printf("\nTotal Interest Paid = %.2f", interestPaid);
    }

    printf("\n");
}
void fdtdr()
{
    float p, r, interest, amount;
    int ch, cho, t;

    printf("\n----- FIXED DEPOSITE-TDR CALCULATOR -----\n\n");
    printf("Enter Lump Sum Deposit Amount : ");
    scanf("%f", &p);
    printf("Enter Annual Interest Rate(%%) : ");
    scanf("%f", &r);

    printf("\n1.Years\n");
    printf("2.Months\n");
    printf("3.Days\n");
    printf("\nEnter Your Choice(1-3): ");
    scanf("%d", &ch);

    if (ch == 1)
    {
        printf("Enter No.Of Years : ");
        scanf("%d", &t);
    }
    else if (ch == 2)
    {
        printf("Enter No.Of Months : ");
        scanf("%d", &t);
    }
    else if (ch == 3)
    {
        printf("Enter No.Of Days : ");
        scanf("%d", &t);
    }
    else
    {
        printf("Invalid Choice!");
    }

    if (ch == 1)
    {
        interest = (p * r * t) / 100;
        amount = p + interest;
        printf("\n----- FIXED DEPOSITE YEARLY -----\n");
        printf("\nTotal interest = %.2f\n", interest);
        printf("Total amount = %.2f\n", amount);
        printf("\nYou want to receive interest in \n 1.Monthly\n 2.Quarterly\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            interest = interest / (t * 12);
            printf("Monthly Interest = %.2f\n", interest);
            break;
        case 2:
            interest = interest / (t * 4);
            printf("Quarterly Interest = %.2f\n", interest);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    else if (ch == 2)
    {
        interest = (p * r * (t / 12.0)) / 100;
        amount = p + interest;
        printf("\n----- FIXED DEPOSITE MONTHLY -----\n");
        printf("\nTotal interest = %.2f\n", interest);
        printf("Total amount = %.2f\n", amount);
        printf("\nYou want to receive interest in \n 1.Monthly\n 2.Quarterly\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:

            interest = interest / (t * 12);
            printf("Monthly Interest = %.2f\n", interest);
            break;
        case 2:

            interest = interest / (t * 4);
            printf("Quarterly Interest = %.2f\n", interest);
            break;
        default:

            printf("Invalid choice!");
            break;
        }
    }
    else if (ch == 3)
    {
        interest = (p * r * (t / 365.0)) / 100;
        amount = p + interest;
        printf("\n----- FIXED DEPOSITE DAYS -----\n");
        printf("Total interest = %.2f\n", interest);
        printf("Total amount = %.2f", amount);
        printf("\nYou want to receive interest in \n 1.Monthly\n 2.Quarterly\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            interest = interest / (t * 12);
            printf("Monthly Interest = %.2f\n", interest);
            break;
        case 2:
            interest = interest / (t * 4);
            printf("Quarterly Interest = %.2f\n", interest);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    printf("\n");
}
void fdstdr()
{

    float p,r,interest,amount;
    int ch,t,cho,n;
    printf("\n----- FIXED DEPOSITE-STDR -----\n");
    printf("\nEnter Lump Sum Deposit Amount : ");
    scanf("%f",&p);
    printf("Enter Annual Interest Rate(%%): ");
    scanf("%f",&r);

    printf("\n1.Years\n");
    printf("2.Months\n");
    printf("3.Days\n");
    printf("\nEnter Your Choice(1-3) : ");
    scanf("%d",&ch);


    if(ch==1)
    {
        printf("Enter No.Of Years : ");
        scanf("%d",&t);
    }
    else if(ch==2)
    {
        printf("Enter No.Of Months : ");
        scanf("%d",&t);
        t=t/12;
    }
    else if(ch==3)
    {
        printf("Enter No.Of Days : ");
        scanf("%d",&t);
        t=t/365;
    }
    else
    {
        printf("Invalid Choice!");
    }
        amount = p* pow(1+(r/(4*100)),4*t);
        interest = amount-p;
        printf("\n----- FIXED DEPOSITE STDR -----\n");
        printf("\nTotal interest = %.2f\n",interest);
        printf("Maturity amount = %.2f\n",amount);
        printf("Total Deposite = %.2f",p);

        printf("\n");
}
void recurring()
{
    float DA, AI;
    int ch, year;
    float MaturityAmount, TotalDeposite, TotalInterest;
    float i, quarters, months;

    printf("\n----- RECURRING DEPOSITE CALCULATOR -----\n\n");
    printf("Enter Monthly Deposite Amount : ");
    scanf("%f", &DA);

    printf("Enter Annual Interest Rate (in %%): ");
    scanf("%f", &AI);

    printf("\n1. Yearly");
    printf("\n2. Monthly\n");

    printf("\nEnter your choice (1-2) : ");
    scanf("%d", &ch);

    if (ch == 1)
    {
        printf("Enter term in years : ");
        scanf("%d", &year);
        months = year * 12;
    }
    else if (ch == 2)
    {
        printf("Enter term in months : ");
        scanf("%d", &year);
        months = year;
    }
    else
    {
        printf("Invalid Choice!");
        return;
    }

    TotalDeposite = DA * months;


    i = AI / 400.0;
    quarters = months / 3.0;

    MaturityAmount = DA * (pow(1 + i, quarters) - 1) /
                     (1 - pow(1 + i, -1.0 / 3.0));

    TotalInterest = MaturityAmount - TotalDeposite;

    printf("\n----- RECURRING DEPOSITE DETAILS -----\n");
    printf("\nMaturing Amount = %.2f", MaturityAmount);
    printf("\nTotal Deposits = %.2f", TotalDeposite);
    printf("\nTotal Interest = %.2f", TotalInterest);

    printf("\n");
}
void scss()
{
    float p,r,interest,amount;

    printf("\n----- SENIOR CITIZEN SAVING SCHEME -----\n");
    printf("\nEnter Lump Sum Deposite Amount : ");
    scanf("%f",&p);
    printf("Enter Annual Interest Rate (%%) : ");
    scanf("%f",&r);
    printf("Term\n5 Years");

    interest = (p*r*5) /100;
    amount = p + interest;

    printf("\n----- SCSS DETAILS -----\n");
    printf("\nTotal interest = %.2f\n",interest);
    printf("Total amount = %.2f\n",amount);

    interest = interest / (5*4);
    printf("Quaterly interest = %.2f\n",interest);
}
void kvp()
{
    float p,interest,amount;

    printf("\n----- KISAN VIKAS PATRA -----\n\n");
    printf("\nEnter Lump Sum Deposit Amount: ");
    scanf("%f",&p);
    amount = p* pow(1+(7.5/100),9.583);
    interest = amount-p;
    printf("\n----- KVP DETAILS -----\n");
    printf("\nTotal interest = %.2f\n",interest);
    printf("Maturity amount = %.2f\n",amount);
    printf("Total Deposit = %.2f",p);
    printf("\n");
}
