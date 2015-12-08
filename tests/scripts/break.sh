#!/bin/sh

echo "-----Test 1 : normal break-----"
#Break 1 is normal behaviour
for i in {1..10}
{
	for j in {1..10}
	{
		echo $j
		if [ $j -eq 5 ]; then
			break 1;
		fi
	}
}

echo "-----Test 2 : parent break-----"
#Break 2 stop parent loop
for i in {1..10}
{
	for j in {1..10}
	{
		echo $j
		if [ $j -eq 5 ]; then
			break 2;
		fi
	}
}

echo "-----Test 3  : grand parent break-----"
#Break 3 stop grand-parent loop etc....
for k in {1..10}
{
	for i in {1..10}
	{
		for j in {1..10}
		{
			echo $j
			if [ $j -eq 5 ]; then
				break 3;
			fi
		}
	}
}
