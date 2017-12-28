# @param {Integer} n
# @return {Integer}
def count_primes(n)

  if n < 2
    return 0
  end

  is_prime = Array.new n, true

  is_prime[0] = false

  is_prime[1] = false

  i = 2

  while i * i < n

    if is_prime[i]            # If this number is a prime. Its multiples are non-prime.

      j = i * i

      while j < n             # Updating this prime's multiples' records.

        is_prime[j] = false

        j += i
      end
    end

    i += 1
  end

  count = 0

  is_prime.each { |value|

    if value
      count += 1
    end

  }

  count
end

puts count_primes 4

puts count_primes 10