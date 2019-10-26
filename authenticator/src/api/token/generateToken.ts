import { randomBytes } from "crypto";

export function generateToken(): Promise<string> {
    return new Promise((resolve, reject) => randomBytes(42, (error: Error | null, buffer: Buffer) => {
        if (error)
            reject(error);
        else
            resolve(buffer.toString("base64").slice(0, 42))
    }));
}