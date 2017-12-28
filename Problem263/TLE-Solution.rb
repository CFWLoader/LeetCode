# @param {Integer} num
# @return {Boolean}
def is_ugly(num)

  if num <= 0
    return false
  end

  if num == 1
    return true
  end

  while num > 0

    prime = 2

    while prime < num and num % prime != 0
      prime = next_prime prime
    end

    if prime > 5
      return false
    end

    num /= prime
  end

  true
end

def next_prime(num)

  target = num + 1

  while true

    factor = 2

    while factor * factor < target

      # puts "#{factor * factor}, #{target}"

      if target % factor == 0
        break
      end

      factor += 1
    end

    if target % factor != 0
      return target
    end

    target += 1
  end
end

puts is_ugly 6

puts is_ugly 8

puts is_ugly 14

puts is_ugly 937351770