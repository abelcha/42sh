#!/usr/bin/env ruby


def putstr(str)
  puts "\033[34m"
  system(str)
  puts "\033[0m"
  cat = "echo \"" + str + "\" | ./42sh" 
  system(cat)
end

ARGV.each do|str|
  File.readlines(str).each do |line|
    putstr(line)
  end
end
