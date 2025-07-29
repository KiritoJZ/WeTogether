#include "stores/friend_store.h"
#include "stores/login_store.h"
#include "network/api_client.h"

FriendStore &FriendStore::instance() { static FriendStore s; return s; }
FriendStore::FriendStore(QObject *p) : QObject(p) {}

void FriendStore::refresh() {
    auto *api = new ApiClient(this);
    connect(api, &ApiClient::friendsReady, this, [=, this](const QJsonArray &arr){
        emit friendsReady(arr);
        api->deleteLater();
    });
    api->fetchFriends(LoginStore::instance().token());
}
