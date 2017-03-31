
def contents(passedarray)
 puts "\nArray contents: "
   puts passedarray
end

def combine(onedim, onedim2)
 puts "\nCombined array contents: "
 
 combine = Array.new()
 combine = onedim + onedim2
   return combine
end

def size(passedarray)
puts "Array Size: "
puts passedarray.size
end

puts "====1D Array 1 Testing===="
onedim = Array.new()
onedim = [ 'Hello' , 'There', 'My', 'Name']
contents(onedim)
size(onedim)

puts "====1D Array 2 Testing===="
onedim2 = Array.new()
onedim2 = [ 'Is' , 'Malique', 'Stefan', 'Dowridge']
contents(onedim2)
size(onedim2)



puts "====1D Array  1 + 2 Combined===="

g = combine(onedim, onedim2)
puts g
size(g)

