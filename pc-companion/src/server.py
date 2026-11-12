from flask import Flask, request, jsonify
import subprocess
import webbrowser
import os

app = Flask(__name__)

# Localhost-only starter. Do not expose to LAN until authentication is added.
@app.get("/status")
def status():
    return jsonify({"ok": True, "service": "NAVY CONTROL PAD PC companion",
                    "note": "Starter endpoint; hardware integration not configured."})

@app.post("/media/<action>")
def media(action):
    # TODO: implement Windows media keys using a reviewed library and test each key.
    allowed = {"play-pause", "next", "previous", "volume-up", "volume-down", "mute"}
    if action not in allowed:
        return jsonify({"error": "unsupported action"}), 400
    return jsonify({"accepted": action, "implemented": False}), 501

@app.post("/launch")
def launch():
    # Do not accept arbitrary command lines from the network.
    name = request.json.get("name", "")
    allowed_apps = {}  # Add explicit allow-listed app paths here.
    if name not in allowed_apps:
        return jsonify({"error": "app is not allow-listed"}), 403
    os.startfile(allowed_apps[name])
    return jsonify({"launched": name})

if __name__ == "__main__":
    app.run(host="127.0.0.1", port=8765, debug=False)
