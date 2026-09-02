namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus{troll,guest,user,mod};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
    enum class Action{read,write,remove};
    
// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster, AccountStatus viewer) {
    bool troll_post = (poster == AccountStatus::troll);
    bool troll_viewer = (viewer == AccountStatus::troll);

    return (troll_post and troll_viewer) or 
            (!troll_post and troll_viewer) or 
            (!troll_post and !troll_viewer);
}
    
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus account_status) {   
    switch(account_status){
        case AccountStatus::mod: 
            return true;
        case AccountStatus::user: 
        case AccountStatus::troll: 
            return (action == Action::read) or (action == Action::write);
        case AccountStatus::guest: 
            return (action == Action::read);
        default: 
            return false;
    }
}
    
// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus account1, AccountStatus account2) {
    switch(account1) {
        case AccountStatus::guest: 
            return false;
        case AccountStatus::troll: 
            return account2 == AccountStatus::troll;
        case AccountStatus::user:
        case AccountStatus::mod:
            return (account2 == AccountStatus::user) or 
                    (account2 == AccountStatus::mod);
        default: return false;
    }
}
    
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus acc1, AccountStatus acc2) {
    switch(acc1) {
        case AccountStatus::troll:
            return false;
        case AccountStatus::guest:
            return acc2 == AccountStatus::troll;
        case AccountStatus::user:
            return acc2 == AccountStatus::guest or acc2 == AccountStatus::troll;
        default: return acc2 != AccountStatus::mod;
    }
}  // namespace hellmath
}