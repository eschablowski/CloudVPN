import getToken from "./authentication/getToken";
(async (): Promise<void> => {
    const token = await getToken();
    console.log(token);
})()