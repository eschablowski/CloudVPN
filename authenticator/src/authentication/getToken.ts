import superagent from "superagent";

export default async (): Promise<string> => {
    const res = await superagent.get("google.com");
    return res.text;
}