#Malique S. Dowridge
#Dr. Ndjatou
#03/28/17
#Lab 3
#CS 3820 – Dr. Ndjatou

def computeFinalScore(tavge, exam)

score = (0.4 * tavge) + (0.6 * exam)
return score
end

def printComment(grade)
   if grade == 'A'
   puts "Very Good!"

   elsif grade == 'B'
  puts "Good!"

   elsif grade == 'C'
 puts "Satisfactory!"

   elsif grade == 'D'
 puts "need improvement!"

   elsif grade == 'F'
 puts "Poor!"  
end  
end


def readTestScores()
testt = 0
puts "==Enter Student ID=="
iDnum = gets.to_i

puts "==Enter Final Exam Score=="
exam = gets.to_f

puts "==ENTER ALL TEST SCORES=="
$i = 1
$num = 8

while $i < $num  do
   puts("Enter Test Score for test ##$i" )
   testt += gets.to_f
   $i +=1
end

testt = testt / 7
score = computeFinalScore(testt, exam)
grade = getLetterGrade(score)


puts "\n\nStudent ID: #{iDnum} "  
puts "Test Average is: #{testt.round(2)}" 
puts "Final Exam Score is: #{exam}" 
puts "Final Grade is: #{score.round(2)}"
puts "Letter Grade: #{grade}"
puts "Comment: "
printComment(grade)
end

def getLetterGrade(score)
if score >= 90
return 'A'

elsif score > 80 && score < 90
return 'B'

elsif score > 70 && score < 80
return 'C'

elsif score > 60 && score < 70
return 'D'

elsif score < 60
return 'F'
end
end

puts readTestScores()

finish = gets # prevents the window from closing