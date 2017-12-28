# @param {String} secret
# @param {String} guess
# @return {String}
def get_hint(secret, guess)

  bulls = 0; cows = 0

  index = 0

  size = secret.size

  while index < size

    if secret[index] == guess[index]

      bulls += 1

      secret[index] = guess[index] = 'X'

    end

    index += 1

  end

  i = 0; j = 0

  while i < size

    if secret[i] != 'X'

      j = 0

      while j < size

        if guess[j] != 'X' and secret[i] == guess[j]

          cows += 1

          secret[i] = 'X'

          guess[j] = 'X'

        end

        j += 1

      end
    end

    i += 1
  end

  bulls.to_s + 'A' + cows.to_s + 'B'

end


puts get_hint '1111', '1111'

puts get_hint '1807', '7810'
puts get_hint '1123', '0111'

