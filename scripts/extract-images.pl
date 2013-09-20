#!/usr/bin/perl -w

# extract-images.pl
#
# A simple script to extract the individual sprites from the console grid and build a HTML file for the end-user..

use strict;
use warnings;
use Data::Dumper;

use Image::Magick;

my $image_filename = "../assets/consoles.png";
my $dat_filename = "console_grid.dat";

# Open the data file.
open(my $datfile, "<", $dat_filename) || die "Can't open $dat_filename: $!";

while (my $line = <$datfile>) {
	chomp $line;

	if ($line =~ /\[[\w\s]+\]/) {
		# Remove the brackets
		$line =~ s/[\[\]]//g;
		print "</ul>\n<h2>$line:</h2>\n<ul>\n";
	} elsif ($line =~ /([\w]+)(\s+)([0-9]+\s+[0-9]+)/) {
		# Parse the fields.
		my ($id, $col, $row) = $line =~ /[\w]+/g;
		print "<li><img src=\"sprites/$id.png\" /> <ul><li><b>ID:</b> $id</li> <li><b>X:</b> $col</li> <li><b>Y:</b> $row</li></ul></li>\n";

		# Open the image.
		my ($image, $ret);
		$image = Image::Magick->new();
		$ret = $image->Read($image_filename);
		die "Couldn't open $image_filename: $ret" if "$ret";

		# Extract the sprite.
		my $sprite = $image->Crop(geometry => "36x38+" . $col * 37.1 . "+" . $row * 38);
		$ret = $image->Write("sprites/$id.png");
		die "Couldn't save sprites/$id.png: $ret" if "$ret";
	}
}
