#include "accountcontroller.h"
#include "user.h"

void AccountController::form()
{
    userLogout();  // 強制的にログアウト
    render();   // formビューを表示
}

void AccountController::login()
{
    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    User user = User::authenticate(username, password);
    if (!user.isNull()) {
        userLogin(&user);
        // redirect(QUrl(...));
        redirect(url("Article","index"));
    } else {
        QString message = "Login failed";
        texport(message);
        render("form");
    }
}

void AccountController::logout()
{
    userLogout();
    redirect(urla("form"));  // ログインフォームへリダイレクト
}

// Don't remove below this line
T_DEFINE_CONTROLLER(AccountController)
