#include "http.h"
#include <stdio.h>

int main() {
    ft_http_client_t* http = 0;

    ft_http_init();

    http = ft_http_new();

    while (1) {
        char ch = getchar();

        if (ch == -1) {
            usleep(100*1000);
            continue;
        }
        if (ch == 'q')
            break;

        switch (ch) {
        case 'a':
        {
            const char* body = NULL;
            //ft_http_set_timeout(http, 4);

            body = ft_http_sync_request(http, "http://112.124.110.213:8005/OS01", M_POST);
            printf("ft_http get:%s\n", body);
        }
        break;
        case 'd':
        {
            int code = 0;

            //ft_http_set_timeout(http, 10*1000);

            code = ft_http_sync_download_file(http, "http://180.97.81.180:55647/test.jpg", "155195031592.jpg");
            printf("ft_http get:%d\n", code);
        }
        break;
        }
    }

    if (http) {
        ft_http_destroy(http);
    }
    ft_http_deinit();
}
