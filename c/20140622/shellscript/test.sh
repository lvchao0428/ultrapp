#!/bin/sh

echo $PWD

for((i=0; i<10; i++))
do
	echo $i
done

for i in $(seq 10)
do 
	echo $i
done

echo $i

if [ $i -eq 10 ]
then 
	echo "loop for  ending"
fi


if [ $i -lt 11 ]
then
	echo "i < 11"
fi

if [ $i -gt 11 ]
then
	echo "i > 11"
else
	echo "i < 11"
fi


function start 
{
	touch start.sh
	chmode 744 start.sh
	echo "test" > start.sh
	cat / dev/null > start.sh
	echo "#!/bin/sh" >> start.sh
	echo "sleep 100" >> start.sh
	./start.sh & 	
	echo "start 10 exec ending ..."
	
}

case $1 in
	start | begin)
	start ;;
	stop | end)
	echo "end ..." ;;
	*)
	echo "ignore..." ;;
esac




