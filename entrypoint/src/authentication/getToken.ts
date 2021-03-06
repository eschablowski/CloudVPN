import superagent from "superagent";

export default async (): Promise<string> => {
    const res = await superagent.get("authenticator.cloudvpn.com:8080/api/token");
    return res.text;
}