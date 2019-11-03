import { randomBytes } from "crypto";
import { redis } from "config";
import { promisify } from "util";

async function write(id: string, data: string, expire = 0): Promise<boolean> {
  const r = await redis;
  return new Promise((resolve, reject) => {
    const val = r.set(id, data, "PX", expire, "NX");
    if (val) resolve(true);
    else reject();
  });
}

async function get(id: string): Promise<string>{
  return promisify((await redis).get)(id);
}

export async function generateToken(id: string): Promise<string> {
  let token;
  do {
    token = randomBytes(42).toString("base64");
  } while (await write(token, id));
  return token;
}

export function getUser(token: string): Promise<string> {
  return get(token);
}
