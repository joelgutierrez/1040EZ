//This program calculate the 1040ez tax form quickly with minimal input.
//  main.cpp
//  1040EZ.cpp
//
//  Created by Joel Gutierrez on 7/21/16.
//  Copyright © 2016 Joel Gutierrez. All rights reserved.
//


#include <iostream>
using namespace std;


#define TAXINTEREST 1500.00                     //line-2 instructions
#define WORKSHEET_LINE_A 350.00                 //backside of form, line-A
#define MIN_STD_DEDUCT 1050.00                  //backside of form, line-B
#define DEPENDENT_SINGLE_MAX 6300.00            //dependent and single
#define DEPENDENT_FILING_JOINTLY_MAX 12600.00   //dependent and married filing jointly
#define INDEPENDENT_SINGLE 10300.00             //independent and single
#define INDEPENDENT_FILING_JOINTLY 20600.00     //independent and married filing jointly

/* determines the adjusted gross income on line-4 of the 1040EZ tax form
 @param x line 1 of 1040EZ tax form
 @param y line 2 of 1040EZ tax form
 @param z line 3 of 1040EZ tax form
 @return the adjusted gross income aka line-4
 */
double adjusted_gross_income(double x, double y, double z)  //line-4 = adds lines 1,2,3 of 1040ez form together.
{
    if(y>TAXINTEREST)
    {
        cout << "You CANNOT use the 1040EZ form!" << endl;
        return 0;
    }
    else
    {
        double gross_income = x + y + z;
        cout << "Your adjusted gross income is: " << gross_income << endl;
        return gross_income;
    }
}

/* determines line-5-C of 1040EZ form
 @param one is line-1 of the form
 @return line-5-C for return form
 */
double line_5_C_worksheet (double one)
{
    double line_A = one + WORKSHEET_LINE_A;
    double line_B = MIN_STD_DEDUCT;
    double line_C = 0;
    if(line_A > line_B)
    {
        double line_C = line_A;
        return line_C;
    }
    else
    {
        line_C = line_B;
        return line_C;
    }
}

int main()

{
    const string SINGLE = "yes";
    const string DEPENDENT = "yes";
    
    cout << "type the values of lines 1, 2, and 3. ";
    cout << "hit ENTER after each entry: (ie: 3157.10) " << endl;
    double line_one, line_two, line_three;
    cin >> line_one >> line_two >> line_three;
    
    //if the user checked off yes or no on box YOU
    cout << "On line 5, if you checked the \"You\" box, type \"yes\" or \"no\" ";
    cout << "then hit the ENTER key. " << endl;
    string user_yes_no;                                          
    cin >> user_yes_no;
    
    cout << "Did you check off the box \"Spouse\", type \"yes\" or \"no\" then ";
    cout << "hit the ENTER key. " << endl;
    string spouse_yes_no;
    cin >> spouse_yes_no;
    
    cout << "are you single? type \"yes\" or \"no\" then hit ENTER: " << endl;
    string single_married;
    cin >> single_married;
    
    cout << "type in your federal income tax withheld a.k.a. ";
    cout << "line 7: (ie: 3157.10) " << endl;
    double line_7;
    cin >> line_7;
    
    cout << "type 8a value then hit ENTER: " << endl;
    double line_8A;
    cin >> line_8A;
    
    cout << "type 8b value then hit ENTER: " << endl;
    double line_8B;
    cin >> line_8B;
    
    double line_four = adjusted_gross_income(line_one, line_two, line_three);
    double line_5_front = 0.00;
    
    //user checked at least one box in line-5
    if(user_yes_no == DEPENDENT || spouse_yes_no == DEPENDENT)     
    {
        double line_E = 0;
        double line_F = 0;
        //YOU & SPOUSE checked off + line 5 worksheet
        if(user_yes_no == DEPENDENT && spouse_yes_no == DEPENDENT)    
        {
            cout << "line 5A = " << line_one + WORKSHEET_LINE_A << endl;
            double line_five_C = line_5_C_worksheet(line_one);
            cout << "line 5C = " << line_five_C << endl;
            double line_D = DEPENDENT_FILING_JOINTLY_MAX;
            cout << "line 5D = " << line_D << endl;
            if(line_five_C < line_D)
            {
                line_E = line_five_C;
            }
            else
            {
                line_E = line_D;
            }
            cout << "line 5E = " << line_E << endl;
            double line_F = 0.00;
            cout << "line F = " << line_F << endl;
            
        }
        //only YOU was checked off + line 5 worksheet
        else if(user_yes_no == DEPENDENT)             
        {
            cout << "line 5A = " << line_one + WORKSHEET_LINE_A << endl;
            double line_five_C = line_5_C_worksheet(line_one);
            cout << "line 5C = " << line_five_C << endl;
            double line_D = DEPENDENT_SINGLE_MAX;
            cout << "line 5D = " << line_D << endl;
            if(line_five_C < line_D)
            {
                line_E = line_five_C;
            }
            else
            {
                line_E = line_D;
            }
            cout << "line 5E = " << line_E << endl;
            double line_F = 0.00;
            if(single_married == SINGLE)
            {
                line_F = 0.00;
                cout << "line F = " << line_F << endl;
            }
            else
            {
                line_F = 4000.00;
                cout << "line F = " << line_F << endl;
            }
            
        }
        //only SPOUSE was checked off + line 5 worksheet
        else                                            
        {
            cout << "line 5A = " << line_one + WORKSHEET_LINE_A << endl;
            double line_five_C = line_5_C_worksheet(line_one);
            cout << "line 5C = " << line_five_C << endl;
            double line_D = DEPENDENT_FILING_JOINTLY_MAX;
            cout << "line 5D = " << line_D << endl;
            if(line_five_C < line_D)
            {
                line_E = line_five_C;
            }
            else
            {
                line_E = line_D;
            }
            cout << "line 5E = " << line_E << endl;
            double line_F = 4000.00;
            cout << "line F = " << line_F << endl;
        }
        double line_5G = line_E + line_F;
        cout << "line 5G & line 5 = " << line_5G << endl;
        line_5_front = line_5G;
    }
    //no boxes checked in line-5
    else                                                
    {
        if(single_married == SINGLE)
        {
            line_5_front = INDEPENDENT_SINGLE;
        }
        else
        {
            line_5_front = INDEPENDENT_FILING_JOINTLY;
        }
    }
    
    double line_six = 0.00;
    if(line_5_front > line_four)
    {
        line_six = 0.00;
    }
    else
    {
        line_six = line_four - line_5_front;
    }
    cout << "line 6 = " << line_six << endl;
    
    double line_9 = line_7 + line_8A;
    cout << "line 9 = " << line_9 << endl;
    
    cout << "enter line 10 value then hit ENTER: " << endl;
    double line_10;
    cin >> line_10;
    
    cout << "enter line 11 value then hit ENTER: " << endl;
    double line_11;
    cin >> line_11;
    
    double line_12 = line_10 + line_11;
    cout << "line 12 = " << line_12 << endl;
    
    double line_13a = 0;
    double line_14 = 0;
    if(line_9 > line_12)
    {
        line_13a = line_9 - line_12;
        cout << "line_13a = " << line_13a << endl;
    }
    else
    {
        line_14 = line_12 - line_9;
        cout << "line_14 = " << line_14 << endl;
    }
    
    
    return (0);
}