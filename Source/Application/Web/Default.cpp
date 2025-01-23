/************************************************** Description
 * *******************************************************/
/*
    File : main.cpp
    Programmer : Mohammad Lotfi
    Used : main
    Design Pattern : none
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2025/1/23
*/
/************************************************** Warnings
 * **********************************************************/
/*
    Only for learning
*/
/************************************************** Wizards
 * ***********************************************************/
/*
    Nothing
*/
/************************************************** Includes
 * **********************************************************/
#include "../Module/Print.hpp"
#include "../../OpenWRT/staging_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/usr/include/cjson/cJSON.h"
/************************************************** Defineds
 * **********************************************************/
/*
    Nothing
*/
/************************************************** Names
 * *************************************************************/
/*
    Nothing
*/
/************************************************** Variables
 * *********************************************************/
void MAIN_Blink(void);
/************************************************** Opjects
 * ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions
 * *********************************************************/
/* The main function start of program in cpp language */
int main() {

    // Get the content length
    char buffer[1024];
    char *content_length_str = getenv("CONTENT_LENGTH");
    int content_length = content_length_str ? atoi(content_length_str) : 0;

    Print((char*)"Content-type: application/json\n\n");

    if (content_length > 0) {
        // Read the JSON payload
        char *json_payload = (char *)malloc(content_length + 1);
        fread(json_payload, 1, content_length, stdin);
        json_payload[content_length] = '\0';

        // Parse the JSON
        cJSON *json = cJSON_Parse(json_payload);
        if (!json) {
            Print((char*)"{\"error\": \"Invalid JSON\"}\n");
            free(json_payload);
            return 1;
        }

        // Extract values from JSON
        cJSON *param1 = cJSON_GetObjectItemCaseSensitive(json, "param1");
        cJSON *param2 = cJSON_GetObjectItemCaseSensitive(json, "param2");

        // Respond with extracted values
        snprintf(buffer, sizeof(buffer), "{\"received\": {\"param1\": \"%s\", \"param2\": \"%s\"}}\n",
            param1 ? param1->valuestring : "null",
            param2 ? param2->valuestring : "null");
        Print (buffer);

        // Clean up
        cJSON_Delete(json);
        free(json_payload);
    } else {
        Print((char*)"{\"error\": \"No data received\"}\n");
    }

    return 0;
}
/************************************************** Tasks
 * *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors
 * ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
