def add(a_number, another_number)
 return a_number + another_number
end

def sub(a_number, another_number)
 return a_number - another_number
end

def mul(a_number, another_number)
 return a_number * another_number
end

def div(a_number, another_number)
  return a_number / another_number
end

puts "\nWelcome to M.S.D's Ruby Calculator!"
puts "1 for Additon"
puts "2 for Subtraction"
puts "3 for Multiplication"
puts "4 for Division"
puts "5 to exit"

input = gets.to_i #converts string input to interger.

if input == 1
puts "Enter two numbers to be added"
x = gets.to_i
y = gets.to_i

    a = add(x,y)
    puts "\naddition: "
    puts a

    
elsif input == 2
puts "Enter two numbers to be subtracted"
x = gets.to_i
y = gets.to_i
    s = sub(x,y)
	puts "\nsubtraction: "
    puts s

    
    elsif input == 3
puts "Enter two numbers to be multiplied"
x = gets.to_i
y = gets.to_i
    m = mul(x,y)
	puts "\nmultiplication: "
    puts m

  
   elsif input == 4
    puts "Enter two numbers to be divided"
x = gets.to_f
y = gets.to_f
    d = div(x,y)
	puts "\ndivision: "
    puts d 
	
	   elsif input == 5
puts "Terminating Program"
end 
