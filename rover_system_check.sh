#!/bin/bash
# Generate a random battery percentage (0-100)
batterylevel=$((RANDOM % 101))
echo "Battery Level: $batterylevel%"
# Check battery level
if [ "$batterylevel" -lt 20 ]; then
    echo "Battery low! Return to base!"
    exit 1
fi
# Check network connectivity
ping -c 1 -W 2 google.com > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Communication failure!"
    exit 1
fi
# If both checks pass
echo "All systems operational!"
exit 0

