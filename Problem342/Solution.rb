# @param {Integer} num
# @return {Boolean}
def is_power_of_four(num)

  if num <= 0
    return false
  end

  (num & num - 1) == 0 and (num & 0x55555555) == num

end

# sum = 0
#
# 0.upto(15) {|pow|
#
#   print "#{4**pow} bin_val: #{(4**pow).to_s 2} \n"
#
#   sum += 4**pow
#
# }
#
# print "Sum: #{sum.to_s 16}\n"       # 55555555