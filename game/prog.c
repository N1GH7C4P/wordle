/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:44:56 by llonnrot          #+#    #+#             */
/*   Updated: 2022/02/24 23:34:37 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define RED printf("\033[0;31m");
#define GREEN printf("\033[0;32m");
#define YELLOW printf("\033[0;33m");
#define BLUE printf("\033[0;34m");
#define PURPLE printf("\033[0;35m");
#define CYAN printf("\033[0;36m");
#define WHITE printf("\033[0;37m");
#define EC printf("\033[0m");

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	check_guess(char *answer, char *guess, int i, int j)
{
	char *temp = ft_strdup(answer);

	while (i < 5)
	{
		if (guess[i] == answer[i])
		{
			guess[i] -= 32;
		}
		else
		{
			while (temp[j] != '\0')
			{
				if (guess[i] == temp[j])
					break;
				j++;
			}
			if (temp[j] == '\0')
				guess[i] = '-';
		}
		j = 0;
		i++;
	}
}

void	game(char *answer, int i)
{
	int len = 75;
	int index = 0;
	int border = len;
	int border2 = 2;
	char *guess = ft_strnew(100);
	char *compare_guess = ft_strdup(answer);
	while (compare_guess[i] != '\0')
	{
		compare_guess[i] = ft_toupper(compare_guess[i]);
		i++;
	}
	printf("\n\n		       	Guess the \033[0;32mWORD\033[0m in \033[0;33msix\033[0m tries. Each guess must be a valid \033[0;33mfive-letter\033[0m word, typed with \033[0;31mlower-case\033[0m!!\n\n							Hit the \033[0;32menter\033[0m key to submit.\n\n	       	After each guess, the case \033[0;36mdistinction\033[0m of the \033[0;33mletters\033[0m will change to show how close your \033[0;32mguess\033[0m was to the  \033[0;32mword\033[0m.\n");
	printf("\n				      	\033[0;33mLower-case letter\033[0m = letter was found in word but \033[0;31mnot\033[0m in right position\n\n				     	\033[0;32mUpper-case letter\033[0m = letter was found and in the right position\n\n						\033[0;35m'-'\033[0m = blank character, as in letter was \033[0;31mnot\033[0m found.\n");
	while (border2 > 0)
	{
		while(border > 0)
		{
			printf("\033[0;31m-\033[0;37m-");
			border--;
		}
		printf("\n");
		border = len;
		border2--;
	}
	border2 = 2;
	printf("\n\n						\033[0;34m1st\033[0m try! Type in your \033[0;32mguess\033[0m and hit enter!\n");
	printf("\n							Your guess : ");
	scanf("%s", guess);
	check_guess(answer, guess, 0, 0);
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("						                                  \033[0;36m.''.\033[0m       \n");
		printf("						      \033[0;32m.''.\033[0m      \033[0;34m.\033[0m        \033[0;33m*''*\033[0m    \033[0;36m:_\\/_:\033[0m     \033[0;35m.\033[0m \n");
		printf("						     \033[0;32m:_\\/_:\033[0m   \033[0;34m_\\(/_\033[0m  \033[0;33m.:.*_\\/_*\033[0m   \033[0;36m: /\\ :\033[0m  \033[0;35m.'.:.'.\033[0m\n");
		printf("						 \033[0;31m.''.\033[0m\033[0;32m: /\\ :\033[0m   \033[0;34m./)\\\033[0m   \033[0;33m':'* /\\ *\033[0m \033[0;36m:  '..'.\033[0m  \033[0;35m-=:o:=-\033[0m\n");
		printf("						\033[0;31m:_\\/_:\033[0m\033[0;32m'.:::.\033[0m    \033[0;34m' *''*\033[0m    \033[0;33m* '.\'/.'\033[0m \033[0;36m_\\(/_\033[0m\033[0;35m'.':'.'\033[0m\n");
		printf("						\033[0;31m: /\\ :\033[0m \033[0;32m:::::\033[0m     \033[0;34m*_\\/_*\033[0m     \033[0;33m-= o =-\033[0m  \033[0;36m/)\\\033[0m    \033[0;35m'  *\033[0m\n");
		printf("						 \033[0;31m'..'\033[0m  \033[0;32m':::'\033[0m     \033[0;34m* /\\ *\033[0m     \033[0;33m.'/.\'.\033[0m   \033[0;36m'\033[0m\n");
		printf("						      \033[0;33m*\033[0m            \033[0;34m*..*\033[0m         \033[0;33m:\033[0m\n");
		printf("						       \033[0;33m*\033[0m\n");
		printf("						        \033[0;33m*\033[0m\n");
		printf("\n");
		RED printf("\n							CONGRATLUATIONS! Your answer is correct!\n"); EC
		RED printf("					                                                        ,---,  \n"); EC
		RED printf("					      ,-.----.                                       ,`--.' |  \n"); EC
		BLUE printf("					      \\    / \\     ,---,       .--.--.    .--.--.   |   :  :  \n"); EC
		GREEN printf("					      |   :    \\   '  .' \\     /  /    '. /  /    '. '   '  ;  \n"); EC
		YELLOW printf("					      |   |  .\\ : /  ;    '.  |  :  /`. /|  :  /`. / |   |  |  \n"); EC
		RED printf("					      .   :  |: |:  :       \\ ;  |  |--` ;  |  |--`  '   :  ;  \n"); EC
		CYAN printf("					      |   |   \\ ::  |   /\\   \\|  :  ;_   |  :  ;_    |   |  '  \n"); EC
		PURPLE printf("					      |   : .   /|  :  ' ;.   :\\  \\    `. \\  \\    `. '   :  |  \n"); EC
		RED printf("					      ;   | |`-' |  |  ;/  \\   \\`----.   \\ `----.   \\;   |  ;  \n"); EC
		BLUE printf("					      |   | ;    '  :  | \\  \\ ,'__ \\  \\  | __ \\  \\  |`---'. |  \n"); EC
		GREEN printf("					      :   ' |    |  |  '  '--' /  /`--'  //  /`--'  / `--..`;  \n"); EC
		YELLOW printf("					      :   : :    |  :  :      '--'.     /'--'.     / .--,_     \n"); EC
		CYAN printf("					      |   | :    |  | ,'        `--'---'   `--'---'  |    |`.  \n"); EC
		PURPLE printf("					      `---'.|    `--''                               `-- -`, ; \n"); EC
		RED printf("					        `---`                                           '---`  \n"); EC
		printf("\n");
		exit (0);
	}
	else
	{
		printf("\n\n						Your answer was \033[0;31mincorrect\033[0m, please try again!\n\n");
		printf("							Feedback : ");
		while (guess[index] != '\0')
		{
			if (ft_islower(guess[index]) == 1)
			{
				YELLOW printf("%c", guess[index]); EC
			}
			if (ft_isupper(guess[index]) == 1)
			{
				GREEN printf("%c", guess[index]); EC
			}
			if (guess[index] == '-')
			{
				printf("%c", guess[index]);
			}
			index++;
		}
		index = 0;
		printf("\n\n");
		while (border2 > 0)
		{
			while(border > 0)
			{
				printf("\033[0;31m-\033[0;37m-");
				border--;
			}
			printf("\n");
			border = len;
			border2--;
		}
		border2 = 2;
		printf("\n\n						\033[0;34m2nd\033[0m try! Type in your \033[0;32mguess\033[0m and hit enter!\n");
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	border2 = 2;
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("						                                  \033[0;36m.''.\033[0m       \n");
		printf("						      \033[0;32m.''.\033[0m      \033[0;34m.\033[0m        \033[0;33m*''*\033[0m    \033[0;36m:_\\/_:\033[0m     \033[0;35m.\033[0m \n");
		printf("						     \033[0;32m:_\\/_:\033[0m   \033[0;34m_\\(/_\033[0m  \033[0;33m.:.*_\\/_*\033[0m   \033[0;36m: /\\ :\033[0m  \033[0;35m.'.:.'.\033[0m\n");
		printf("						 \033[0;31m.''.\033[0m\033[0;32m: /\\ :\033[0m   \033[0;34m./)\\\033[0m   \033[0;33m':'* /\\ *\033[0m \033[0;36m:  '..'.\033[0m  \033[0;35m-=:o:=-\033[0m\n");
		printf("						\033[0;31m:_\\/_:\033[0m\033[0;32m'.:::.\033[0m    \033[0;34m' *''*\033[0m    \033[0;33m* '.\'/.'\033[0m \033[0;36m_\\(/_\033[0m\033[0;35m'.':'.'\033[0m\n");
		printf("						\033[0;31m: /\\ :\033[0m \033[0;32m:::::\033[0m     \033[0;34m*_\\/_*\033[0m     \033[0;33m-= o =-\033[0m  \033[0;36m/)\\\033[0m    \033[0;35m'  *\033[0m\n");
		printf("						 \033[0;31m'..'\033[0m  \033[0;32m':::'\033[0m     \033[0;34m* /\\ *\033[0m     \033[0;33m.'/.\'.\033[0m   \033[0;36m'\033[0m\n");
		printf("						      \033[0;33m*\033[0m            \033[0;34m*..*\033[0m         \033[0;33m:\033[0m\n");
		printf("						       \033[0;33m*\033[0m\n");
		printf("						        \033[0;33m*\033[0m\n");
		printf("\n");
		RED printf("\n							CONGRATLUATIONS! Your answer is correct!\n"); EC
		RED printf("					                                                        ,---,  \n"); EC
		RED printf("					      ,-.----.                                       ,`--.' |  \n"); EC
		BLUE printf("					      \\    / \\     ,---,       .--.--.    .--.--.   |   :  :  \n"); EC
		GREEN printf("					      |   :    \\   '  .' \\     /  /    '. /  /    '. '   '  ;  \n"); EC
		YELLOW printf("					      |   |  .\\ : /  ;    '.  |  :  /`. /|  :  /`. / |   |  |  \n"); EC
		RED printf("					      .   :  |: |:  :       \\ ;  |  |--` ;  |  |--`  '   :  ;  \n"); EC
		CYAN printf("					      |   |   \\ ::  |   /\\   \\|  :  ;_   |  :  ;_    |   |  '  \n"); EC
		PURPLE printf("					      |   : .   /|  :  ' ;.   :\\  \\    `. \\  \\    `. '   :  |  \n"); EC
		RED printf("					      ;   | |`-' |  |  ;/  \\   \\`----.   \\ `----.   \\;   |  ;  \n"); EC
		BLUE printf("					      |   | ;    '  :  | \\  \\ ,'__ \\  \\  | __ \\  \\  |`---'. |  \n"); EC
		GREEN printf("					      :   ' |    |  |  '  '--' /  /`--'  //  /`--'  / `--..`;  \n"); EC
		YELLOW printf("					      :   : :    |  :  :      '--'.     /'--'.     / .--,_     \n"); EC
		CYAN printf("					      |   | :    |  | ,'        `--'---'   `--'---'  |    |`.  \n"); EC
		PURPLE printf("					      `---'.|    `--''                               `-- -`, ; \n"); EC
		RED printf("					        `---`                                           '---`  \n"); EC
		printf("\n");
		exit (0);
	}
	else
	{
		printf("\n\n						Your answer was \033[0;31mincorrect\033[0m, please try again!\n\n");
		printf("							Feedback : ");
		while (guess[index] != '\0')
		{
			if (ft_islower(guess[index]) == 1)
			{
				YELLOW printf("%c", guess[index]); EC
			}
			if (ft_isupper(guess[index]) == 1)
			{
				GREEN printf("%c", guess[index]); EC
			}
			if (guess[index] == '-')
			{
				printf("%c", guess[index]);
			}
			index++;
		}
		index = 0;
		printf("\n\n");
		while (border2 > 0)
		{
			while(border > 0)
			{
				printf("\033[0;31m-\033[0;37m-");
				border--;
			}
			printf("\n");
			border = len;
			border2--;
		}
		border2 = 2;
		printf("\n\n						\033[0;34m3rd\033[0m try! Type in your \033[0;32mguess\033[0m and hit enter!\n");
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("						                                  \033[0;36m.''.\033[0m       \n");
		printf("						      \033[0;32m.''.\033[0m      \033[0;34m.\033[0m        \033[0;33m*''*\033[0m    \033[0;36m:_\\/_:\033[0m     \033[0;35m.\033[0m \n");
		printf("						     \033[0;32m:_\\/_:\033[0m   \033[0;34m_\\(/_\033[0m  \033[0;33m.:.*_\\/_*\033[0m   \033[0;36m: /\\ :\033[0m  \033[0;35m.'.:.'.\033[0m\n");
		printf("						 \033[0;31m.''.\033[0m\033[0;32m: /\\ :\033[0m   \033[0;34m./)\\\033[0m   \033[0;33m':'* /\\ *\033[0m \033[0;36m:  '..'.\033[0m  \033[0;35m-=:o:=-\033[0m\n");
		printf("						\033[0;31m:_\\/_:\033[0m\033[0;32m'.:::.\033[0m    \033[0;34m' *''*\033[0m    \033[0;33m* '.\'/.'\033[0m \033[0;36m_\\(/_\033[0m\033[0;35m'.':'.'\033[0m\n");
		printf("						\033[0;31m: /\\ :\033[0m \033[0;32m:::::\033[0m     \033[0;34m*_\\/_*\033[0m     \033[0;33m-= o =-\033[0m  \033[0;36m/)\\\033[0m    \033[0;35m'  *\033[0m\n");
		printf("						 \033[0;31m'..'\033[0m  \033[0;32m':::'\033[0m     \033[0;34m* /\\ *\033[0m     \033[0;33m.'/.\'.\033[0m   \033[0;36m'\033[0m\n");
		printf("						      \033[0;33m*\033[0m            \033[0;34m*..*\033[0m         \033[0;33m:\033[0m\n");
		printf("						       \033[0;33m*\033[0m\n");
		printf("						        \033[0;33m*\033[0m\n");
		printf("\n");
		RED printf("\n							CONGRATLUATIONS! Your answer is correct!\n"); EC
		RED printf("					                                                        ,---,  \n"); EC
		RED printf("					      ,-.----.                                       ,`--.' |  \n"); EC
		BLUE printf("					      \\    / \\     ,---,       .--.--.    .--.--.   |   :  :  \n"); EC
		GREEN printf("					      |   :    \\   '  .' \\     /  /    '. /  /    '. '   '  ;  \n"); EC
		YELLOW printf("					      |   |  .\\ : /  ;    '.  |  :  /`. /|  :  /`. / |   |  |  \n"); EC
		RED printf("					      .   :  |: |:  :       \\ ;  |  |--` ;  |  |--`  '   :  ;  \n"); EC
		CYAN printf("					      |   |   \\ ::  |   /\\   \\|  :  ;_   |  :  ;_    |   |  '  \n"); EC
		PURPLE printf("					      |   : .   /|  :  ' ;.   :\\  \\    `. \\  \\    `. '   :  |  \n"); EC
		RED printf("					      ;   | |`-' |  |  ;/  \\   \\`----.   \\ `----.   \\;   |  ;  \n"); EC
		BLUE printf("					      |   | ;    '  :  | \\  \\ ,'__ \\  \\  | __ \\  \\  |`---'. |  \n"); EC
		GREEN printf("					      :   ' |    |  |  '  '--' /  /`--'  //  /`--'  / `--..`;  \n"); EC
		YELLOW printf("					      :   : :    |  :  :      '--'.     /'--'.     / .--,_     \n"); EC
		CYAN printf("					      |   | :    |  | ,'        `--'---'   `--'---'  |    |`.  \n"); EC
		PURPLE printf("					      `---'.|    `--''                               `-- -`, ; \n"); EC
		RED printf("					        `---`                                           '---`  \n"); EC
		printf("\n");
		exit (0);
	}
	else
	{
		printf("\n\n						Your answer was \033[0;31mincorrect\033[0m, please try again!\n\n");
		printf("							Feedback : ");
		while (guess[index] != '\0')
		{
			if (ft_islower(guess[index]) == 1)
			{
				YELLOW printf("%c", guess[index]); EC
			}
			if (ft_isupper(guess[index]) == 1)
			{
				GREEN printf("%c", guess[index]); EC
			}
			if (guess[index] == '-')
			{
				printf("%c", guess[index]);
			}
			index++;
		}
		index = 0;
		printf("\n\n");
		while (border2 > 0)
		{
			while(border > 0)
			{
				printf("\033[0;31m-\033[0;37m-");
				border--;
			}
			printf("\n");
			border = len;
			border2--;
		}
		border2 = 2;
		printf("\n\n						\033[0;34m4th\033[0m try! Type in your \033[0;32mguess\033[0m and hit enter!\n");
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("						                                  \033[0;36m.''.\033[0m       \n");
		printf("						      \033[0;32m.''.\033[0m      \033[0;34m.\033[0m        \033[0;33m*''*\033[0m    \033[0;36m:_\\/_:\033[0m     \033[0;35m.\033[0m \n");
		printf("						     \033[0;32m:_\\/_:\033[0m   \033[0;34m_\\(/_\033[0m  \033[0;33m.:.*_\\/_*\033[0m   \033[0;36m: /\\ :\033[0m  \033[0;35m.'.:.'.\033[0m\n");
		printf("						 \033[0;31m.''.\033[0m\033[0;32m: /\\ :\033[0m   \033[0;34m./)\\\033[0m   \033[0;33m':'* /\\ *\033[0m \033[0;36m:  '..'.\033[0m  \033[0;35m-=:o:=-\033[0m\n");
		printf("						\033[0;31m:_\\/_:\033[0m\033[0;32m'.:::.\033[0m    \033[0;34m' *''*\033[0m    \033[0;33m* '.\'/.'\033[0m \033[0;36m_\\(/_\033[0m\033[0;35m'.':'.'\033[0m\n");
		printf("						\033[0;31m: /\\ :\033[0m \033[0;32m:::::\033[0m     \033[0;34m*_\\/_*\033[0m     \033[0;33m-= o =-\033[0m  \033[0;36m/)\\\033[0m    \033[0;35m'  *\033[0m\n");
		printf("						 \033[0;31m'..'\033[0m  \033[0;32m':::'\033[0m     \033[0;34m* /\\ *\033[0m     \033[0;33m.'/.\'.\033[0m   \033[0;36m'\033[0m\n");
		printf("						      \033[0;33m*\033[0m            \033[0;34m*..*\033[0m         \033[0;33m:\033[0m\n");
		printf("						       \033[0;33m*\033[0m\n");
		printf("						        \033[0;33m*\033[0m\n");
		printf("\n");
		RED printf("\n							CONGRATLUATIONS! Your answer is correct!\n"); EC
		RED printf("					                                                        ,---,  \n"); EC
		RED printf("					      ,-.----.                                       ,`--.' |  \n"); EC
		BLUE printf("					      \\    / \\     ,---,       .--.--.    .--.--.   |   :  :  \n"); EC
		GREEN printf("					      |   :    \\   '  .' \\     /  /    '. /  /    '. '   '  ;  \n"); EC
		YELLOW printf("					      |   |  .\\ : /  ;    '.  |  :  /`. /|  :  /`. / |   |  |  \n"); EC
		RED printf("					      .   :  |: |:  :       \\ ;  |  |--` ;  |  |--`  '   :  ;  \n"); EC
		CYAN printf("					      |   |   \\ ::  |   /\\   \\|  :  ;_   |  :  ;_    |   |  '  \n"); EC
		PURPLE printf("					      |   : .   /|  :  ' ;.   :\\  \\    `. \\  \\    `. '   :  |  \n"); EC
		RED printf("					      ;   | |`-' |  |  ;/  \\   \\`----.   \\ `----.   \\;   |  ;  \n"); EC
		BLUE printf("					      |   | ;    '  :  | \\  \\ ,'__ \\  \\  | __ \\  \\  |`---'. |  \n"); EC
		GREEN printf("					      :   ' |    |  |  '  '--' /  /`--'  //  /`--'  / `--..`;  \n"); EC
		YELLOW printf("					      :   : :    |  :  :      '--'.     /'--'.     / .--,_     \n"); EC
		CYAN printf("					      |   | :    |  | ,'        `--'---'   `--'---'  |    |`.  \n"); EC
		PURPLE printf("					      `---'.|    `--''                               `-- -`, ; \n"); EC
		RED printf("					        `---`                                           '---`  \n"); EC
		printf("\n");
		exit (0);
	}
	else
	{
		printf("\n\n						Your answer was \033[0;31mincorrect\033[0m, please try again!\n\n");
		printf("							Feedback : ");
		while (guess[index] != '\0')
		{
			if (ft_islower(guess[index]) == 1)
			{
				YELLOW printf("%c", guess[index]); EC
			}
			if (ft_isupper(guess[index]) == 1)
			{
				GREEN printf("%c", guess[index]); EC
			}
			if (guess[index] == '-')
			{
				printf("%c", guess[index]);
			}
			index++;
		}
		index = 0;
		printf("\n\n");
		while (border2 > 0)
		{
			while(border > 0)
			{
				printf("\033[0;31m-\033[0;37m-");
				border--;
			}
			printf("\n");
			border = len;
			border2--;
		}
		border2 = 2;
		printf("\n\n						\033[0;34m5th\033[0m try! Type in your \033[0;32mguess\033[0m and hit enter!\n");
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("						                                  \033[0;36m.''.\033[0m       \n");
		printf("						      \033[0;32m.''.\033[0m      \033[0;34m.\033[0m        \033[0;33m*''*\033[0m    \033[0;36m:_\\/_:\033[0m     \033[0;35m.\033[0m \n");
		printf("						     \033[0;32m:_\\/_:\033[0m   \033[0;34m_\\(/_\033[0m  \033[0;33m.:.*_\\/_*\033[0m   \033[0;36m: /\\ :\033[0m  \033[0;35m.'.:.'.\033[0m\n");
		printf("						 \033[0;31m.''.\033[0m\033[0;32m: /\\ :\033[0m   \033[0;34m./)\\\033[0m   \033[0;33m':'* /\\ *\033[0m \033[0;36m:  '..'.\033[0m  \033[0;35m-=:o:=-\033[0m\n");
		printf("						\033[0;31m:_\\/_:\033[0m\033[0;32m'.:::.\033[0m    \033[0;34m' *''*\033[0m    \033[0;33m* '.\'/.'\033[0m \033[0;36m_\\(/_\033[0m\033[0;35m'.':'.'\033[0m\n");
		printf("						\033[0;31m: /\\ :\033[0m \033[0;32m:::::\033[0m     \033[0;34m*_\\/_*\033[0m     \033[0;33m-= o =-\033[0m  \033[0;36m/)\\\033[0m    \033[0;35m'  *\033[0m\n");
		printf("						 \033[0;31m'..'\033[0m  \033[0;32m':::'\033[0m     \033[0;34m* /\\ *\033[0m     \033[0;33m.'/.\'.\033[0m   \033[0;36m'\033[0m\n");
		printf("						      \033[0;33m*\033[0m            \033[0;34m*..*\033[0m         \033[0;33m:\033[0m\n");
		printf("						       \033[0;33m*\033[0m\n");
		printf("						        \033[0;33m*\033[0m\n");
		printf("\n");
		RED printf("\n							CONGRATLUATIONS! Your answer is correct!\n"); EC
		RED printf("					                                                        ,---,  \n"); EC
		RED printf("					      ,-.----.                                       ,`--.' |  \n"); EC
		BLUE printf("					      \\    / \\     ,---,       .--.--.    .--.--.   |   :  :  \n"); EC
		GREEN printf("					      |   :    \\   '  .' \\     /  /    '. /  /    '. '   '  ;  \n"); EC
		YELLOW printf("					      |   |  .\\ : /  ;    '.  |  :  /`. /|  :  /`. / |   |  |  \n"); EC
		RED printf("					      .   :  |: |:  :       \\ ;  |  |--` ;  |  |--`  '   :  ;  \n"); EC
		CYAN printf("					      |   |   \\ ::  |   /\\   \\|  :  ;_   |  :  ;_    |   |  '  \n"); EC
		PURPLE printf("					      |   : .   /|  :  ' ;.   :\\  \\    `. \\  \\    `. '   :  |  \n"); EC
		RED printf("					      ;   | |`-' |  |  ;/  \\   \\`----.   \\ `----.   \\;   |  ;  \n"); EC
		BLUE printf("					      |   | ;    '  :  | \\  \\ ,'__ \\  \\  | __ \\  \\  |`---'. |  \n"); EC
		GREEN printf("					      :   ' |    |  |  '  '--' /  /`--'  //  /`--'  / `--..`;  \n"); EC
		YELLOW printf("					      :   : :    |  :  :      '--'.     /'--'.     / .--,_     \n"); EC
		CYAN printf("					      |   | :    |  | ,'        `--'---'   `--'---'  |    |`.  \n"); EC
		PURPLE printf("					      `---'.|    `--''                               `-- -`, ; \n"); EC
		RED printf("					        `---`                                           '---`  \n"); EC
		printf("\n");
		exit (0);
	}
	else
	{
		printf("\n\n						Your answer was \033[0;31mincorrect\033[0m, please try again!\n\n");
		printf("							Feedback : ");
		while (guess[index] != '\0')
		{
			if (ft_islower(guess[index]) == 1)
			{
				YELLOW printf("%c", guess[index]); EC
			}
			if (ft_isupper(guess[index]) == 1)
			{
				GREEN printf("%c", guess[index]); EC
			}
			if (guess[index] == '-')
			{
				printf("%c", guess[index]);
			}
			index++;
		}
		index = 0;
		printf("\n\n");
		while (border2 > 0)
		{
			while(border > 0)
			{
				printf("\033[0;31m-\033[0;37m-");
				border--;
			}
			printf("\n");
			border = len;
			border2--;
		}
		border2 = 2;
		printf("\n\n						\033[0;31mLAST\033[0m try! Type in your \033[0;32mguess\033[0m and hit enter!\n");
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("						                                  \033[0;36m.''.\033[0m       \n");
		printf("						      \033[0;32m.''.\033[0m      \033[0;34m.\033[0m        \033[0;33m*''*\033[0m    \033[0;36m:_\\/_:\033[0m     \033[0;35m.\033[0m \n");
		printf("						     \033[0;32m:_\\/_:\033[0m   \033[0;34m_\\(/_\033[0m  \033[0;33m.:.*_\\/_*\033[0m   \033[0;36m: /\\ :\033[0m  \033[0;35m.'.:.'.\033[0m\n");
		printf("						 \033[0;31m.''.\033[0m\033[0;32m: /\\ :\033[0m   \033[0;34m./)\\\033[0m   \033[0;33m':'* /\\ *\033[0m \033[0;36m:  '..'.\033[0m  \033[0;35m-=:o:=-\033[0m\n");
		printf("						\033[0;31m:_\\/_:\033[0m\033[0;32m'.:::.\033[0m    \033[0;34m' *''*\033[0m    \033[0;33m* '.\'/.'\033[0m \033[0;36m_\\(/_\033[0m\033[0;35m'.':'.'\033[0m\n");
		printf("						\033[0;31m: /\\ :\033[0m \033[0;32m:::::\033[0m     \033[0;34m*_\\/_*\033[0m     \033[0;33m-= o =-\033[0m  \033[0;36m/)\\\033[0m    \033[0;35m'  *\033[0m\n");
		printf("						 \033[0;31m'..'\033[0m  \033[0;32m':::'\033[0m     \033[0;34m* /\\ *\033[0m     \033[0;33m.'/.\'.\033[0m   \033[0;36m'\033[0m\n");
		printf("						      \033[0;33m*\033[0m            \033[0;34m*..*\033[0m         \033[0;33m:\033[0m\n");
		printf("						       \033[0;33m*\033[0m\n");
		printf("						        \033[0;33m*\033[0m\n");
		printf("\n");
		RED printf("\n							CONGRATLUATIONS! Your answer is correct!\n"); EC
		RED printf("					                                                        ,---,  \n"); EC
		RED printf("					      ,-.----.                                       ,`--.' |  \n"); EC
		BLUE printf("					      \\    / \\     ,---,       .--.--.    .--.--.   |   :  :  \n"); EC
		GREEN printf("					      |   :    \\   '  .' \\     /  /    '. /  /    '. '   '  ;  \n"); EC
		YELLOW printf("					      |   |  .\\ : /  ;    '.  |  :  /`. /|  :  /`. / |   |  |  \n"); EC
		RED printf("					      .   :  |: |:  :       \\ ;  |  |--` ;  |  |--`  '   :  ;  \n"); EC
		CYAN printf("					      |   |   \\ ::  |   /\\   \\|  :  ;_   |  :  ;_    |   |  '  \n"); EC
		PURPLE printf("					      |   : .   /|  :  ' ;.   :\\  \\    `. \\  \\    `. '   :  |  \n"); EC
		RED printf("					      ;   | |`-' |  |  ;/  \\   \\`----.   \\ `----.   \\;   |  ;  \n"); EC
		BLUE printf("					      |   | ;    '  :  | \\  \\ ,'__ \\  \\  | __ \\  \\  |`---'. |  \n"); EC
		GREEN printf("					      :   ' |    |  |  '  '--' /  /`--'  //  /`--'  / `--..`;  \n"); EC
		YELLOW printf("					      :   : :    |  :  :      '--'.     /'--'.     / .--,_     \n"); EC
		CYAN printf("					      |   | :    |  | ,'        `--'---'   `--'---'  |    |`.  \n"); EC
		PURPLE printf("					      `---'.|    `--''                               `-- -`, ; \n"); EC
		RED printf("					        `---`                                           '---`  \n"); EC
		printf("\n");
		exit (0);
	}
	else
	{
		printf("\033[0;31m\n\t\t\t	Your answer was incorrect.. You are out of tries! Too bad... (ノಠ益ಠ)ノ彡┻━┻\n\n\033[0m");
		printf("\n\n							Correct answer : %s\n", answer);
	}
	printf("\n\n");
	while (border2 > 0)
	{
		while(border > 0)
		{
			printf("\033[0;31m-\033[0;37m-");
			border--;
		}
		printf("\n");
		border = len;
		border2--;
	}
	border2 = 2;

}

int	main(void)
{
	int		fd;
	int		i, j, word;
	char	*line;
	char	**dictionary;
	time_t	t;
	j = 0;
	i = 0;
	srand((unsigned) time(&t));
	word = rand() % 3000;
	if (word > 2315)
	{
		while (word > 2315)
		word = rand() % 3000;
	}
	dictionary = (char **)malloc(sizeof(char *) * 2316);
	while (i < 2316)
	{
		dictionary[i] = ft_strnew(5);
		i++;
	}
	i = 0;
	fd = open("dictionary", O_RDONLY);
	while (ft_get_next_line(fd, &line) == 1)
	{
		while (line[i] != '\0')
		{
			dictionary[j][i] = line[i];
			i++;
		}
		i = 0;
		j++;
		free (line);
	}
	free (line);
	char *answer = ft_strdup(dictionary[word]);
	game(answer, 0);
	exit (0);
}
