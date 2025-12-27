#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, score = 0;
    char answer;
    int asked[10] = {0}; // to avoid repeating questions
    int q;

    // Questions
    char questions[10][200] = {
        "What is the capital of India?",
        "Which planet is known as the Red Planet?",
        "Who is known as the Father of the Indian Constitution?",
        "Which is the largest ocean in the world?",
        "What is the national animal of India?",
        "Which gas is most abundant in Earth's atmosphere?",
        "Who invented the telephone?",
        "Which is the longest river in the world?",
        "Which country is known as the Land of the Rising Sun?",
        "What is the SI unit of force?"
    };

    // Options
    char options[10][4][50] = {
        {"Mumbai", "New Delhi", "Kolkata", "Chennai"},
        {"Earth", "Venus", "Mars", "Jupiter"},
        {"Mahatma Gandhi", "Jawaharlal Nehru", "B. R. Ambedkar", "Rajendra Prasad"},
        {"Indian Ocean", "Atlantic Ocean", "Arctic Ocean", "Pacific Ocean"},
        {"Lion", "Elephant", "Tiger", "Leopard"},
        {"Oxygen", "Nitrogen", "Carbon dioxide", "Hydrogen"},
        {"Thomas Edison", "Alexander Graham Bell", "Nikola Tesla", "James Watt"},
        {"Amazon", "Yangtze", "Mississippi", "Nile"},
        {"China", "Thailand", "Japan", "South Korea"},
        {"Joule", "Pascal", "Newton", "Watt"}
    };

    // Correct answers
    char correctAnswers[10] = {'B','C','C','D','C','B','B','D','C','C'};

    srand(time(0)); // seed for randomness

    printf("GENERAL KNOWLEDGE QUIZ GAME\n");
    printf("Questions will appear in random order\n");
    printf("Choose A, B, C or D\n\n");

    for (i = 0; i < 10; i++) {
        // generate a random unused question index
        do {
            q = rand() % 10;
        } while (asked[q] == 1);

        asked[q] = 1;

        printf("%d. %s\n", i + 1, questions[q]);
        printf("A. %s\n", options[q][0]);
        printf("B. %s\n", options[q][1]);
        printf("C. %s\n", options[q][2]);
        printf("D. %s\n", options[q][3]);

        printf("Your answer: ");
        scanf(" %c", &answer);

        if (answer == correctAnswers[q] || answer == correctAnswers[q] + 32)
            score++;

        printf("\n");
    }

    printf("QUIZ COMPLETED\n");
    printf("Your Score: %d / 10\n", score);

    if (score >= 8)
        printf("Excellent performance\n");
    else if (score >= 5)
        printf("Good performance\n");
    else
        printf("Needs improvement\n");

    return 0;
}
