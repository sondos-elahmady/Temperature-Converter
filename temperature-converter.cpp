#include <iostream>
using namespace std;

#define SIZE 5

int menu()
{
    int choice;
    cout << "Menu:\n";
    cout << "1: Input temperatures.\n";
    cout << "2: Convert temperatures to Fahrenheit.\n";
    cout << "3: Display the highest, lowest, and average temperature.\n";
    cout << "4: Exit program.\n";
    cin >> choice;
    return choice;
}

void inputTemperatures(float temp[], char unit[])
{
    cout << "Please input 5 temperatures and their units (C, K, F).\n";
    for (int i = 0; i < SIZE; i++)
        cin >> temp[i] >> unit[i];
}

float convertToF(float temp, char& unit)
{
    switch (unit)
    {
    case 'C': 
    case 'c': 
        temp = temp * 1.8 + 32; 
        unit = 'F'; 
        break;
    case 'K': 
    case 'k': 
        temp = (temp - 273.15) * 1.8 + 32; 
        unit = 'F'; 
        break;
    case 'F': 
    case 'f': 
        // Already in Fahrenheit, no conversion needed
        break;
    default:
        cout << "Invalid unit: " << unit << ". Assuming Fahrenheit.\n";
        unit = 'F';
        break;
    }
    return temp;
}

void analyzeTemperatures(float temp[])
{
    float sum = temp[0], max = temp[0], min = temp[0];
    for (int i = 1; i < SIZE; i++)
    {
        sum += temp[i];
        if (temp[i] > max)
            max = temp[i];
        if (temp[i] < min)
            min = temp[i];
    }
    cout << "Maximum temperature is " << max << " F\n";
    cout << "Minimum temperature is " << min << " F\n";
    cout << "Average temperature is " << sum / SIZE << " F\n";
}

int main()
{
    float temp[SIZE];
    char unit[SIZE];
    int choice;

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: 
            inputTemperatures(temp, unit); 
            break;
        case 2:
            for (int i = 0; i < SIZE; i++)
                temp[i] = convertToF(temp[i], unit[i]);
            break;
        case 3: 
            analyzeTemperatures(temp); 
            break;
        case 4: 
            cout << "Exiting program.\n";
            break;
        default: 
            cout << "Invalid input, try again.\n"; 
            break;
        }
    } while (choice != 4);

    cout << "Thank You!\n";
    return 0;
}
