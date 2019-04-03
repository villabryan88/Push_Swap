
if((scalar @ARGV) != 1)
{
	print "$0 [NUMBER]\n";
	exit;
}

my @range = (-1000..1000);
my $nb = $ARGV[0];
my @res = rand_samp($nb, @range);
print "@res";
 
sub rand_samp
{
   my ($n, @n) = (shift,@_);
   return 0 unless ($n < scalar @n);
   my %seen = ();
   until (keys %seen == $nb)
   {
      $seen{$range[rand @range]} = 1;
   }    
   return(keys %seen);
}
