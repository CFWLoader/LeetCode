# @param {String} version1
# @param {String} version2
# @return {Integer}
def compare_version(version1, version2)

  version1_value = 0; version2_value = 0

  version1_index = 0; version2_index = 0

  while version1_index < version1.size or version2_index < version2.size

    version1_value, version1_index = get_version_value version1, version1_index

    version2_value, version2_index = get_version_value version2, version2_index

    if version1_value > version2_value
      return 1
    elsif version1_value < version2_value
      return -1
    end

  end

  0

end

def get_version_value(version_str, start_index)

  unless start_index < version_str.size
    return 0, start_index
  end

  tail_index = start_index + 1

  while tail_index < version_str.size and version_str[tail_index] != '.'
    tail_index += 1
  end

  return version_str[start_index, tail_index].to_i, tail_index + 1

end


version1 = '10.255.355.4'

version2 = '10.255.355.4'

puts compare_version version1, version2

puts compare_version '1.0', '1'