#include <stdio.h>
float calculateDeductions(float income);

float calculateTax(float income) {
    float tax = 0;
    float taxableIncome = income - calculateDeductions(income);

    if (taxableIncome <= 250000) {
        tax = 0; // No tax for income up to 2.5 lakhs
    } else if (taxableIncome > 250000 && taxableIncome <= 500000) {
        tax = (taxableIncome - 250000) * 0.05; // 5% tax for income between 2.5 to 5 lakhs
    } else if (taxableIncome > 500000 && taxableIncome <= 1000000) {
        tax = 12500 + (taxableIncome - 500000) * 0.2; // 20% tax for income between 5 to 10 lakhs
    } else {
        tax = 112500 + (taxableIncome - 1000000) * 0.3; // 30% tax for income above 10 lakhs
    }

    return tax;
}

//to calculate deductions under section 80C
float calculateDeductions(float income) {
    float deductions = 0;
    float maxDeduction = 150000; // Maximum deduction limit under section 80C 1.5lakh

    // Assuming some calculations for deductions, like investments in PPF, EPF, etc.
    deductions = income * 0.10; // Example: 10% of income can be considered for deductions

    return (deductions > maxDeduction) ? maxDeduction : deductions;
}

// Function to calculate exemptions
float calculateExemptions() {
    float exemptions = 50000; // Standard exemption limit 50k

    // Additional exemptions can be added here if applicable

    return exemptions;
}

int main() {
    float income;
    float tax;
    float deductions;
    float exemptions;

    // Get income input from user
    printf("Enter your annual income: ");
    scanf("%f", &income);

    // Calculate deductions and exemptions
    deductions = calculateDeductions(income);
    exemptions = calculateExemptions();

    // Calculate tax
    tax = calculateTax(income);

    // Display tax calculation result
    printf("Your estimated tax liability for the year is: %.2f\n", tax);

    // Tax planning suggestions+6+6+++
    if (tax > 0) {
        printf("\nTax Planning Suggestions:\n");
        printf("- Utilize deductions under Section 80C: %.2f\n", deductions);
        printf("- Avail exemptions: %.2f\n", exemptions);
        printf("- Plan investments wisely to optimize tax liability.\n");
    }

    return 0;
}

