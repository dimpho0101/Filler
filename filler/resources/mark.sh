# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 11:36:14 by zbatik            #+#    #+#              #
#    Updated: 2018/09/08 16:50:20 by diputu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

play_filler () {
	echo PLAYING\ AGAINSTS\ $1\ ON\ MAP\ $2 >> result.log
	wins=0
	for count in {1..5}
	do
		p1=$((1 + $RANDOM % 2))
		if [ $p1  == 1 ]; then
			p2=2
		else
   			p2=1
		fi
		./filler_vm -p$p1 $3 -p$p2 ./players/$1.filler -q -f ./maps/map0$2
		winner=$(sed -n '2p' filler.trace)
		echo $winner >> result.log
		if [ "$winner" == "$3 won" ]; then 
			wins=$(echo $wins + 1 | bc)
		fi
		if [ $wins == 3 ]; then
			break
		fi
	done
}

echo Please enter your filler name:
echo example:
echo ./me.filler
read filler

rm result.log
touch result.log

players='champely abanlin hcao grati carli superjeannot'

for player in $players
do
	for	map in {0..2}
	do
		play_filler $player $map $filler
	done
done
