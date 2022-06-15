#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996)

typedef struct transaction
{
	char sender[65];
	char receiver[65];
	char strAmount[65];
	float amount;

	char result[65];
	unsigned char unsigedResult[65];
}TS;

void setSender(TS* ts, char name[])
{
	strcpy(ts->sender, name);
}

void setReceiver(TS* ts, char name[])
{
	strcpy(ts->receiver, name);
}

void setAmount(TS* ts, float amount)
{
	ts->amount = amount;
	sprintf(ts->strAmount, "%f", ts->amount);
}

void setResult(TS* ts)
{
	strcpy(ts->result, "");

	strcat(ts->result, ts->sender);
	strcat(ts->result, ts->receiver);
	strcat(ts->result, ts->strAmount);

	for (int i = 0; i < 65; i++)
		ts->unsigedResult[i] = ts->result[i];
}

#endif // !TRANSACTION_H