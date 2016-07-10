#! /usr/bin/perl -w

#Yingzhu Zhang, CS 312 Programming Languages
#Assignment 4: myfind.pl
#Citations: 
    #http://perlmaven.com/how-to-process-command-line-arguments-in-perl
    #http://docstore.mik.ua/orelly/perl/sysadmin/ch02_03.htm
    #http://www.perlmonks.org/?node_id=1065701

use strict;
use warnings;
use 5.010;
use Getopt::Long qw(GetOptions);
use Cwd; # module for finding the current working directory

my $name_arg = "";
my $ls_flag;
my $pwd_flag;
my $grep_arg;

my $start_dir = shift;
GetOptions(
    'name=s' => \$name_arg,
    'ls' => \$ls_flag,
    'pwd' => \$pwd_flag,
    'grep=s' => \$grep_arg,
    ) or die "Usage: $0 -name NAME_STR -ls -pwd -grep GREP_STR \n";


if ($start_dir) {
    # do nothing 
} else {
    $start_dir = ".";
}

# Matching shell globs as reg exp
#http://docstore.mik.ua/orelly/perl/cookbook/ch06_10.htm
my $globstr = "";
sub glob2pat {
    $globstr = shift;
    my %patmap = (
        '*' => '.*',
        '?' => '.',
        '[' => '[',
        ']' => ']',
    );
    $globstr =~ s{(.)} { $patmap{$1} || "\Q$1" }ge;
    return $globstr . '$';
}
my @file_with_dir_list = (); #declare and initialize a hash to keep the file name with its assocaited dir
$name_arg =~ s/"//g; # Get rid of the quotation marks for the wild card
$name_arg = glob2pat($name_arg); 

if ($name_arg =~ '\*'){
    $name_arg ='^.'.$name_arg.'$';
}
else {
    $name_arg = $name_arg;
}

my @return;
my $return;
my $grep_file;
my $grep_line;
sub ScanDirectory {
    my ($workdir) = shift;
    my $startdir = &cwd; # keep track of where we began
    chdir($workdir) or die "Unable to enter dir $workdir:$!\n";
    opendir(DIR, ".") or die "Unable to open $workdir:$!\n";
    my @names = readdir(DIR);
    closedir(DIR);
 
    foreach my $name (@names){
        $return = "";
        next if ($name eq "."); 
        next if ($name eq "..");
    
        if (-d $name){ # is this a directory?
            &ScanDirectory($name);
            next;
        }
        elsif (-f $name){
            if ($name =~ m/$name_arg/) {
                push @file_with_dir_list, &cwd;
                push @file_with_dir_list, $name;
            } 
        }
        if ($name_arg) {
            if ($name =~ m/$name_arg/) {
                $return = $name;
            }
        }
        if ($pwd_flag) {
            if ($name =~ m/$name_arg/) {
                $return = &cwd."/".$return;
            }
        }
        if ($ls_flag) {
            if ($name =~ m/$name_arg/) {
                $return = `ls -l $return`;
                $return =~ s/\R//g;
            }
        }
        if ($grep_arg) {
            if ($name =~ m/$name_arg/) {
                open my $grep_file, '<', $name or die $!;
                my $ct;
                while ($grep_line = <$grep_file>) {
                    $ct++;
                    chomp $grep_line;
                    if ($grep_line =~m /$grep_arg/){
                        print "$return: $ct: $grep_line\n";
                    }
                }
                close ($grep_file);
            }
        }
        else {
            if ($return eq "") {
                # do nothing 
            }
            else {
                print $return."\n";
            }
            
        }  
    }
    chdir($startdir) or die "Unable to change to dir $startdir:$!\n";
}

ScanDirectory ($start_dir); # @file_with_dir_list contains dir-file pair, sorta like a hash
