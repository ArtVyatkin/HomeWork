#include <stdio.h>
#include "notationOfExpression.h"

void scanStringWithSpaces(FILE* inputStream, char* stringBuffer)
{
    fflush(inputStream);
    scanf("%[^\n]", stringBuffer);
}

int main()
{
    char infixExpression[maxSizeOfExpression] = "";
    char postfixExpression[maxSizeOfExpression] = "";

    printf("Enter an expression in infix notation:");
    scanStringWithSpaces(stdin, infixExpression);

    double resultOfExpression = 0.0;
    bool isExpressionCorrect = convertInfixToPostfixNotation(infixExpression, postfixExpression);
    if (isExpressionCorrect)
    {
        isExpressionCorrect = calculatePostfixExpression(postfixExpression, &resultOfExpression);
    }

    if (isExpressionCorrect)
    {
        printf("%s = %lf", infixExpression, resultOfExpression);
    }
    else
    {
        printf("You entered an incorrect expression!");
    }

    return 0;
}