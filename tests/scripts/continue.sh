#!/bin/sh

echo "-----Test 1 : normal continue-----"
#Break 1 is normal behaviour
for i in {1..5}
{
	for j in {1..5}
	{
		echo "i = $i && j = $j"
		if [ $j -eq 2 ]; then
			continue 1;
		fi
	}
}

echo "-----Test 2 : parent continue-----"
#Break 1 is normal behaviour
for i in {1..5}
{
	for j in {1..5}
	{
		echo "i = $i && j = $j"
		if [ $j -eq 2 ]; then
			continue 2;
		fi
	}
}
