# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tab_generator.pl                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axlee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:27:21 by axlee             #+#    #+#              #
#    Updated: 2023/07/10 14:27:36 by axlee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}
