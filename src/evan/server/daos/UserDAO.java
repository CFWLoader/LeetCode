package evan.server.daos;

import evan.server.models.User;

/**
 * Created by cfwloader on 4/1/15.
 */
public interface UserDAO {
    boolean saveUser(User user);
    boolean deleteUser(User user);
    boolean updateUser(User user);
    User login(String username, String password);
}
