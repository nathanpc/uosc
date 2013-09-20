#!/usr/bin/perl -w

# extract-images.pl
#
# A simple script to extract the individual sprites from the console grid and build a HTML file for the end-user..

use strict;
use warnings;
use Data::Dumper;

use Image::Magick;

my $dat_filename = "console_grid.dat";
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
		print "<li><img src=\"sprites/$id.png\" /> ID: $id - X: $col - Y: $row</li>\n";

		# Open the image.
		my $image_filename = "../assets/consoles.png";
		my $image = Image::Magick->new();
		$image->Read($image_filename);

		# Extract the sprite.
		my $sprite = $image->Crop(geometry => "36x38+" . $col * 37.1 . "+" . $row * 38);
		$image->Write("sprites/$id.png");
	}
}
