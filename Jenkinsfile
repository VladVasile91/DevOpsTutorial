pipeline {
    agent any

    environment {
        BUILD_SCRIPT = './buildMain.sh'
        TEST_SCRIPT = './runTests.sh'
    }

    stages {
        stage('Build') {
            steps {
                echo "Running build script for branch ${env.BRANCH_NAME}..."
                sh "${BUILD_SCRIPT}"
            }
        }

        stage('Test') {
            steps {
                echo "Running tests..."
                // The '|| true' prevents pipeline crash, letting junit mark it UNSTABLE if tests fail
                sh "${TEST_SCRIPT} || true"
                junit 'test/test_results.xml'
            }
        }
    }

    post {
        success {
            echo "Build and tests succeeded for ${env.BRANCH_NAME}"
            emailext(
                subject: "SUCCESS: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                body: """
                    <h2>Build Successful!</h2>
                    <p>Good news! The pipeline for branch <b>${env.BRANCH_NAME}</b> has finished successfully.</p>
                    <p>Check the console output here: <br>
                    <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>
                """,
                mimeType: 'text/html',
                recipientProviders: [developers(), requestor()]
            )
        }
        unstable {
            echo "Tests failed for ${env.BRANCH_NAME}"
            emailext(
                subject: "UNSTABLE: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                body: """
                    <h2>Build Unstable (Test Failures)</h2>
                    <p>The code compiled for branch <b>${env.BRANCH_NAME}</b>, but some tests failed.</p>
                    <p>Please check the test reports here: <br>
                    <a href="${env.BUILD_URL}testReport">${env.BUILD_URL}testReport</a></p>
                """,
                mimeType: 'text/html',
                recipientProviders: [developers(), requestor()]
            )
        }
        failure {
            echo "Build failed for ${env.BRANCH_NAME}"
            emailext(
                subject: "FAILED: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                body: """
                    <h2>Build Failed</h2>
                    <p>The pipeline for branch <b>${env.BRANCH_NAME}</b> encountered an error and stopped.</p>
                    <p>Check the console logs to see what broke: <br>
                    <a href="${env.BUILD_URL}console">${env.BUILD_URL}console</a></p>
                """,
                mimeType: 'text/html',
                recipientProviders: [developers(), requestor()]
            )
        }
    }
}
