     

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int N;

struct book_data
{
	char book_name[100];
	char author[100];
	char publisher_name[100];
	int version;
	int publishing_year;
	double price;
};

void display(struct book_data val[])
{
	printf("\nBook\tAuthor\tVersion\tYear\tPrice\tPublisher\n");
	printf("-------------------------------------------------");
	for (int ctr = 0; ctr < N; ctr++)
	{
		printf("\n%s\t%s\t%d\t%d\t%.2lf\t%s", val[ctr].book_name, val[ctr].author, val[ctr].version, val[ctr].publishing_year, val[ctr].price, val[ctr].publisher_name);
	}
	printf("\n-------------------------------------------------");
}

void get_details_of_author(struct book_data s[N], char given_author[])
{
	int count = 0;
	char written_book[N][100];
	for (int ctr = 0; ctr < N; ctr++)
	{
		if (!strcmp(s[ctr].author, given_author))
		{
			strcpy(written_book[count], s[ctr].book_name);
			count++;
		}
	}
	if (count == 0)
	{
		printf("\nThere is no details about Author...\n");
	}
	else
	{
		printf("\nThere are %d books written by %s\n", count, given_author);
		printf("\nThe Books written by %s are : ", given_author);
		for (int ctr = 0; ctr < count; ctr++)
		{
			printf("\n%d.%s", ctr + 1, written_book[ctr]);
		}
	}
}

void get_sort_by_price(struct book_data s[N])
{
	struct book_data temp[N];
	for (int ctr = 0; ctr < N; ctr++)
	{
		temp[ctr] = s[ctr];
	}
	for (int ctr = 0; ctr < N; ctr++)
	{
		for (int inr = ctr + 1; inr < N; inr++)
		{
			if (temp[ctr].price > temp[inr].price)
			{
				struct book_data curr = temp[ctr];
				temp[ctr] = temp[inr];
				temp[inr] = curr;
			}
		}
	}
	printf("\nThe details sorted by price :\n");
	display(temp);
}

void get_publisher_details(struct book_data s[N], char given_publisher[], int given_year)
{
	char written_book[N][100];
	int count = 0;
	for (int ctr = 0; ctr < N; ctr++)
	{
		if (!(strcmp(s[ctr].publisher_name, given_publisher)) && s[ctr].publishing_year == given_year)
		{
			strcpy(written_book[count], s[ctr].book_name);
			count++;
		}
	}

	if (count == 0)
	{
		printf("\nThere is no book published by %s in %d\n", given_publisher, given_year);
	}
	else
	{
		printf("\nThe books published by %s in %d are : \n", given_publisher, given_year);
		for (int ctr = 0; ctr < count; ctr++)
		{
			printf("\n%d.%s", ctr + 1, written_book[ctr]);
		}
	}
}

void get_sort_by_author_and_year(struct book_data s[N])
{
	struct book_data temp[N];
	for (int ctr = 0; ctr < N; ctr++)
	{
		temp[ctr] = s[ctr];
	}
	for (int ctr = 0; ctr < N; ctr++)
	{
		for (int inr = ctr + 1; inr < N; inr++)
		{
			int check = strcmp(temp[ctr].author, temp[inr].author);

			if (check > 0)
			{
				struct book_data curr = temp[ctr];
				temp[ctr] = temp[inr];
				temp[inr] = curr;
			}
			else if (check == 0)
			{
				if (temp[ctr].publishing_year > temp[inr].publishing_year)
				{
					struct book_data curr = temp[ctr];
					temp[ctr] = temp[inr];
					temp[inr] = curr;
				}
			}
		}
	}
	printf("\nThe details sorted by author and year :\n");
	display(temp);
}

int main()
{
	printf("Welcome to Book Application\n");
	printf("\nEnter the total number of book details\n");
	scanf("%d", &N);
	struct book_data book[N];
	for (int ctr = 0; ctr < N; ctr++)
	{
		printf("\nEnter the book name for book %d    : ", ctr + 1);
		scanf("%s", book[ctr].book_name);
		printf("Enter the author name for book %d  : ", ctr + 1);
		scanf("%s", book[ctr].author);
		printf("Enter version number for book  %d  : ", ctr + 1);
		scanf("%d", &(book[ctr].version));
		printf("Enter published year for book  %d  : ", ctr + 1);
		scanf("%d", &(book[ctr].publishing_year));
		printf("Enter the book price for book  %d  : ", ctr + 1);
		scanf("%lf", &(book[ctr].price));
		printf("Enter the publisher for  book  %d  : ", ctr + 1);
		scanf("%s", book[ctr].publisher_name);
	}
	
	char option;
	char given_author[100];
	char given_publisher[100];
	int given_year;
	
	
	while (1)
	{
	    
		printf("\n\nEnter Your choice a / b / c / d / q : ");
		scanf("%s", &option);
		option = tolower(option);
		switch (option)
		{
		case 'a':
			printf("\nEnter author name : ");
			scanf("%s", given_author);
			get_details_of_author(book, given_author);
			break;
		case 'b':
			get_sort_by_price(book);
			break;
		case 'c':
			printf("\nEnter publisher name : ");
			scanf("%s", given_publisher);
			printf("\nEnter the year : ");
			scanf("%d",&given_year);
			get_publisher_details(book, given_publisher, given_year);
			break;
		case 'd':
			get_sort_by_author_and_year(book);
			break;
		case 'q':
			printf("\nQuiting the application..... \nThank you for visiting !!!!!");
			exit(0);
			break;
		default:
			printf("\nPlease enter a valid option !!! ");
			break;
		}
	}
	return 0;
}
